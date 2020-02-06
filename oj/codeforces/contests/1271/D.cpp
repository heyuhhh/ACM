/*
 * Author:  heyuhhh
 * Created Time:  2019/12/16 10:45:39
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#define MP make_pair
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
#define Local
#ifdef Local
  #define dbg(args...) do { cout << #args << " -> "; err(args); } while (0)
  void err() { std::cout << '\n'; }
  template<typename T, typename...Args>
  void err(T a, Args...args) { std::cout << a << ' '; err(args...); }
#else
  #define dbg(...)
#endif
void pt() {std::cout << '\n'; }
template<typename T, typename...Args>
void pt(T a, Args...args) {std::cout << a << ' '; pt(args...); }
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//head
const int N = 5000 + 5;

int n, m, k;
int a[N], b[N], c[N];
int latest[N];
int dp[N][N];

void run(){
    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    for(int i = 1; i <= n; i++) latest[i] = i;
    for(int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        latest[v] = max(latest[v], u);
    }
    for(int i = 0; i <= n + 1; i++) {
        for(int j = 0; j < N; j++) {
            dp[i][j] = -INF;
        }
    }
    dp[1][k] = 0;
    for(int i = 1; i <= n; i++) {
        vector <int> costs;
        for(int j = 1; j <= i; j++) {
            if(latest[j] == i) costs.push_back(c[j]);
        }
        sort(all(costs));
        reverse(all(costs));
        for(int j = 0; j < N; j++) {
            if(j >= a[i] && dp[i][j] >= 0) {
                dp[i + 1][j + b[i]] = max(dp[i + 1][j + b[i]], dp[i][j]);   
            }
        }
        for(auto x : costs) {
            for(int j = 0; j < N; j++) {
                if(dp[i + 1][j] >= 0) {
                    dp[i + 1][j - 1] = max(dp[i + 1][j - 1], dp[i + 1][j] + x);   
                }
            }
        }
    }
    int ans = -1;
    for(int i = 0; i < N; i++) ans = max(ans, dp[n + 1][i]);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n >> m >> k) run();
    return 0;
}

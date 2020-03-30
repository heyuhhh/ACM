/*
 * Author:  heyuhhh
 * Created Time:  2020/3/27 19:23:03
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
#include <assert.h>
#define MP make_pair
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
#define Local
#ifdef Local
  #define dbg(args...) do { cout << #args << " -> "; err(args); } while (0)
  void err() { std::cout << '\n'; }
  template<typename T, typename...Args>
  void err(T a, Args...args) { std::cout << a << ' '; err(args...); }
  template <template<typename...> class T, typename t, typename... A> 
  void err(const T <t> &arg, const A&... args) {
  for (auto &v : arg) std::cout << v << ' '; err(args...); }
#else
  #define dbg(...)
#endif
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//head
const int N = 1e3 + 5, MOD = 1e9 + 7;

int n, k;
char s[N];
int dp[N][N];

void add(int &x, int y) {
    x += y;
    if(x >= MOD) x -= MOD;   
}

void run() {
    cin >> n >> k;
    cin >> (s + 1);
    vector <int> v[26];
    for(int i = 1; i <= n; i++) v[s[i] - 'a'].push_back(i);
    dp[0][0] = 1;
    for(int i = 0; i < k; i++) {
        for(int j = 0; j <= n; j++) if(dp[i][j]) {
            for(int t = 0; t < 26; t++) {
                int p = upper_bound(all(v[t]), j) - v[t].begin();   
                if(p < sz(v[t])) add(dp[i + 1][v[t][p]], dp[i][j]);
            }
        }   
    }
    int ans = 0;
    for(int i = 0; i <= n; i++) add(ans, dp[k][i]);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}

/*
 * Author:  heyuhhh
 * Created Time:  2020/2/24 23:25:46
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
const int N = 2e5 + 5;

int n, m;
char s[N];
int p[N];
int sum[N][26];

void run(){
    cin >> n >> m;
    cin >> (s + 1);
    for(int i = 1; i <= m; i++) cin >> p[i]; p[m + 1] = n;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 26; j++) sum[i][j] = sum[i - 1][j];
        ++sum[i][s[i] - 'a'];   
    }
    auto query = [&](int l, int r, int v) {
        return sum[r][v] - sum[l - 1][v];   
    };
    vector <ll> ans(26, 0);
    for(int i = 1; i <= m + 1; i++) {
        for(int j = 0; j < 26; j++) {
            ans[j] += query(1, p[i], j);   
        }
    }
    for(int i = 0; i < 26; i++) cout << ans[i] << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T;
    while(T--) run();
    return 0;
}

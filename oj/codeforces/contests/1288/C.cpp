/*
 * Author:  heyuhhh
 * Created Time:  2020/1/29 15:55:32
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
const int N = 1000 + 5, M = 10 + 5, MOD = 1e9 + 7;

int n, m;
int f[M][N], g[M][N];

void run(){
    for(int i = 1; i <= n; i++) f[1][i] = g[1][i] = 1;
    for(int i = 2; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= j; k++) {
                f[i][j] = (f[i][j] + f[i - 1][k]) % MOD;
            }
            for(int k = j; k <= n; k++) {
                g[i][j] = (g[i][j] + g[i - 1][k]) % MOD;   
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            ans = (ans + 1ll * f[m][i] * g[m][j] % MOD) % MOD;
        }   
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n >> m) run();
    return 0;
}

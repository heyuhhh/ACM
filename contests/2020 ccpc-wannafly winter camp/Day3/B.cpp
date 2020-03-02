/*
 * Author:  heyuhhh
 * Created Time:  2020/2/10 20:45:41
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
const int N = 5000 + 5, MOD = 1e9 + 7;

int fac[N], inv[N];
int qpow(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;   
    }
    return res;   
}
int C(int n, int m) {
    return 1ll * fac[n] * inv[m] % MOD * inv[n - m] % MOD; 
}

void add(int &x, int y) {
    x += y;
    if(x >= MOD) x -= MOD;   
}

vector <int> G[N];
int n;
int sz[N], tmp[N], f[N][N];

void dp(int u, int fa) {
    sz[u] = 1;
    f[u][1] = 1;
    for(auto v : G[u]) if(v != fa) {
        dp(v, u);
        sz[u] += sz[v];
        memset(tmp, 0, sizeof(tmp));
        for(int i = 1; i <= sz[u]; i++) {
            for(int j = max(1, i - sz[v]); j <= min(i, sz[u] - sz[v]); j++) {
                add(tmp[i], 1ll * f[v][i - j] * f[u][j] % MOD * C(i - 1, i - j) % MOD);
            }
        }
        for(int i = 1; i <= sz[u]; i++) f[u][i] = tmp[i];
    }
    for(int i = sz[u]; i >= 0; i--) {
        add(f[u][i], f[u][i + 1]);
    }
}

void run(){
    for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);   
    }
    fac[0] = 1;
    for(int i = 1; i < N; i++) fac[i] = 1ll * fac[i - 1] * i % MOD;
    inv[N - 1] = qpow(fac[N - 1], MOD - 2);
    for(int i = N - 2; i >= 0; i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % MOD;
    dp(1, 0);
    int ans = f[1][1];
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n) run();
    return 0;
}

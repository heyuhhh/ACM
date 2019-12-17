/*
 * Author:  heyuhhh
 * Created Time:  2019/12/14 14:56:05
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
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
const int N = 5e4 + 5, M = 155, MOD = 10007;

int n, k;
int f[N][M], g[N][M];
vector <int> G[N];
int s[M][M], fac[M], inv[M];

ll qpow(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;   
    }
    return ans;   
}
void init() {
    s[0][0] = 1;
    for(int i = 1; i < M; i++)
        for(int j = 1; j <= i; j++)
            s[i][j] = (s[i - 1][j] * j + s[i - 1][j - 1]) % MOD;
    fac[0] = 1;
    for(int i = 1; i < M; i++) fac[i] = 1ll * fac[i - 1] * i % MOD;
    inv[M - 1] = qpow(fac[M - 1], MOD - 2);
    for(int i = M - 2; i >= 0; i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % MOD;
}
void dfs(int u, int fa) {
    f[u][0] = 1;
    for(int j = 0; j < sz(G[u]); j++) {
        int v = G[u][j];
        if(v != fa) {
            dfs(v, u);
            for(int i = 0; i <= k; i++) {
                f[u][i] = (f[u][i] + f[v][i]) % MOD;
                if(i) f[u][i] = (f[u][i] + f[v][i - 1]) % MOD;  
            }
        }
    }
}
void dfs2(int u, int fa) {
    for(int j = 0; j < sz(G[u]); j++) { 
        int v = G[u][j];
        if(v != fa) {
            for(int i = 0; i <= k; i++) {
                g[v][i] = (g[v][i] + g[u][i] - f[v][i] + MOD) % MOD;
                if(i) g[v][i] = (g[v][i] + g[u][i - 1] - f[v][i - 1] + MOD - f[v][i - 1] + MOD) % MOD;
                if(i > 1) g[v][i] = (g[v][i] - f[v][i - 2] + MOD) % MOD; 
            }
            dfs2(v, u);
        }
    }
}
void run(){
    //cin >> n >> k;
    //for(int i = 1; i < n; i++) {
        //int u, v; cin >> u >> v;
        //G[u].push_back(v);
        //G[v].push_back(u);
    //}
    int L,now,A,B,Q;
    cin >> n >> k >> L >> now >> A >> B >> Q;
    for(int i = 1; i < n; i++) {
        now = (now * A + B) % Q;
        int tmp = i < L ? i : L;
        int x = i - now % tmp, y = i + 1;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(1, 0);
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= k; j++)
            g[i][j] = f[i][j];
    dfs2(1, 0);
    for(int i = 1; i <= n; i++) {
        int ans = 0;
        for(int j = 0; j <= k; j++) {
            ans = (ans + 1ll * fac[j] * s[k][j] * g[i][j]) % MOD;  
        } 
        printf("%d\n", ans);
    }
}

int main() {
    init(); run();
    return 0;
}

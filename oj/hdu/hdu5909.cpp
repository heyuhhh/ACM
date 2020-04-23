/*
 * Author:  heyuhhh
 * Created Time:  2020/4/23 19:52:41
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
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
  void err() { std::cout << std::endl; }
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
const int N = 1000 + 5, M = 10, MOD = 1e9 + 7;

vector <int> G[N];

int n, m;
int v[N];
int f[N][1 << M], g[N][1 << M];
int a[1 << M], b[1 << M];

void FWT_xor(int *a, int n, int op) {
    static int inv2 = (MOD + 1) / 2;
    for(int i = 1; i < n; i <<= 1)
        for(int p = i << 1, j = 0; j < n; j += p)
            for(int k = 0; k < i; k++) {
                int X = a[j + k], Y = a[i + j + k];
                a[j + k] = (X + Y) % MOD; a[i + j + k] = (X + MOD - Y) % MOD;
                if(op == -1) a[j + k] = 1ll * a[j + k] * inv2 % MOD, a[i + j + k] = 1ll * a[i + j + k] * inv2 % MOD;
            }                
}

void dfs(int u, int fa) {
    for (int i = 0; i < m; i++) g[u][i] = 0;
    ++g[u][0];
    for (auto v : G[u]) if (v != fa) {
        dfs(v, u);
        for (int i = 0; i < m; i++) {
            a[i] = g[u][i];
            b[i] = f[v][i];   
        }
        ++b[0];
        FWT_xor(a, m, 1), FWT_xor(b, m, 1);
        for (int i = 0; i < m; i++) {
            a[i] = 1ll * a[i] * b[i] % MOD;   
        }
        FWT_xor(a, m, -1);
        for (int i = 0; i < m; i++) {
            g[u][i] = a[i];   
        }
    }
    for (int i = 0; i < m; i++) {
        f[u][i ^ v[u]] = g[u][i];
    }
}

int ans[1 << M];

void run() {
    cin >> n >> m;
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; i++) G[i].clear();
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);   
    }
    dfs(1, 0);
    for (int j = 0; j < m; j++) {
        ans[j] = 0;
        for (int i = 1; i <= n; i++) {
            ans[j] = (ans[j] + f[i][j]) % MOD;
        }   
    }
    for(int i = 0; i < m; i++) {
        cout << ans[i] << " \n"[i == m - 1];   
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T; while(T--)
    run();
    return 0;
}

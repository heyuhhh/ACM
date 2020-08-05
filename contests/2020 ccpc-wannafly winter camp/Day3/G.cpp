/*
 * Author:  heyuhhh
 * Created Time:  2020/1/14 14:23:18
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
const int N = 5e5 + 5;

int n, k;

struct Edge {
    int v, w, next;     
}e[N << 1];
int head[N], tot;
void adde(int u, int v, int w) {
    e[tot].v = v; e[tot].w = w; e[tot].next = head[u]; head[u] = tot++;
}
bool chk[N];
int sz[N];
ll f[N][2], g[N][2], L[N];
ll ans[N];

void dfs(int u, int fa) {
    sz[u] = (chk[u] == true);
    for(int i = head[u]; i != -1; i = e[i].next) {
        int v = e[i].v, w = e[i].w; 
        if(v == fa) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
}

void dfs2(int u, int fa) {
    for(int i = head[u]; i != -1; i = e[i].next) {
        int v = e[i].v, w = e[i].w;
        if(v == fa) continue;
        dfs2(v, u);
        if(sz[v]) {
            ans[u] += ans[v] + w;
            if(f[v][0] + w > f[u][0]) {
                f[u][1] = f[u][0];
                g[u][1] = g[u][0];
                f[u][0] = f[v][0] + w;
                g[u][0] = v;
            } else if(f[v][0] + w > f[u][1]) {
                f[u][1] = f[v][0] + w;
                g[u][1] = v;   
            }
        }
    }   
}

void dfs3(int u, int fa, ll h) {
    for(int i = head[u]; i != -1; i = e[i].next) {
        int v = e[i].v, w = e[i].w; 
        if(v == fa) continue;
        ll mx;
        if(g[u][0] == v) {
        	mx = max(h, f[u][1]);	
		} else {
        	mx = max(h, f[u][0]);	
		}
		if (sz[v] == k) {
			dfs3(v, u, 0);
		} else {
			L[v] = mx + w;
        	dfs3(v, u, L[v]);	
		}
        
    }   
}

void dfs4(int u, int fa) {
    for(int i = head[u]; i != -1; i = e[i].next) {
        int v = e[i].v, w = e[i].w;
        if(v == fa) continue;
        ans[v] = ans[u] - 2ll * (sz[v] > 0) * w + 2ll * (k - sz[v] > 0) * w;
        dfs4(v, u);
    }   
}

void run(){
	cin >> n >> k;
    memset(head, -1, sizeof(head)); tot = 0;
    for(int i = 1; i < n; i++) {
        int u, v, w; cin >> u >> v >> w;
        adde(u, v, w); adde(v, u, w);
    }
    for(int i = 1; i <= k; i++) {
        int x; cin >> x;
        chk[x] = 1;
    }
    dfs(1, 0);
    dfs2(1, 0);
    dfs3(1, 0, 0);
    ans[1] <<= 1;
    dfs4(1, 0);
    for(int i = 1; i <= n; i++) ans[i] -= max(L[i], f[i][0]);
    for(int i = 1; i <= n; i++) cout << ans[i] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
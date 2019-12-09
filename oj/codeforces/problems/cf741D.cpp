/*
 * Author:  heyuhhh
 * Created Time:  2019/11/15 16:10:20
 */
#include <bits/stdc++.h>
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

int n;
char s[N];
vector <int> g[N];
int dis[N], sz[N], bson[N], d[N];
int f[1 << 22];
int ans[N];

void dfs(int u, int fa) {
    sz[u] = 1; 
    int mx = 0;
    d[u] = d[fa] + 1;
    if(fa) dis[u] = (dis[fa] ^ (1 << (s[u] - 'a')));
    for(auto v : g[u]) {
        dfs(v, u);
        sz[u] += sz[v];
        if(sz[v] > mx) {
            mx = sz[v]; bson[u] = v;
        }
    }
}

int Max, D;

void upd(int u) {
    if(f[dis[u]]) Max = max(Max, f[dis[u]] + d[u] - D);
    for(int i = 0; i < 22; i++) if(f[dis[u] ^ (1 << i)]) {
        Max = max(Max, f[dis[u] ^ (1 << i)] + d[u] - D);
    }    
}

void upd2(int u) {
    f[dis[u]] = max(f[dis[u]], d[u]);
}

void go(int u) {
    upd(u);
    for(auto v : g[u]) go(v);
}

void go2(int u) {
    upd2(u);    
    for(auto v : g[u]) go2(v);   
}

void clear(int u) {
    f[dis[u]] = 0;
    for(auto v : g[u]) clear(v);   
}

void dfs2(int u, int fa, int op) {
    for(auto v : g[u]) if(v != bson[u]) dfs2(v, u, 0);
    if(bson[u]) dfs2(bson[u], u, 1);
    for(auto v : g[u]) Max = max(Max, ans[v]);
    D = 2 * d[u];
    for(auto v : g[u]) if(v != bson[u]) {
        go(v); go2(v); 
    }
    upd(u); upd2(u);
    ans[u] = Max;
    if(!op) {
        clear(u), Max = 0;
    }
}

void run(){
    for(int i = 2; i <= n; i++) {
        int p;
        scanf("%d %c", &p, &s[i]);
        g[p].push_back(i);
    }
    dfs(1, 0);
    dfs2(1, 0, 1);
    for(int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
}

int main() {
    while(cin >> n) run();
	return 0;
}

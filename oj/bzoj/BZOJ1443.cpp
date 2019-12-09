/*
 * Author:  heyuhhh
 * Created Time:  2019/11/6 21:34:15
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
const int N = 105;

int n, m;
int col[N * N];
char s[N];
int mp[N][N], tot;

#define _S heyuhhh
template <class T>
struct Dinic{
    struct Edge{
        int v, next;
        T flow;
        Edge(){}
        Edge(int v, int next, T flow) : v(v), next(next), flow(flow) {}
    }e[500005];
    int head[N * N], tot;
    int dep[N * N];
    void init() {
        memset(head, -1, sizeof(head)); tot = 0;
    }
    void adde(int u, int v, T w, T rw = 0) {
        e[tot] = Edge(v, head[u], w);
        head[u] = tot++;
        e[tot] = Edge(u, head[v], rw);
        head[v] = tot++;
    }
    bool BFS(int _S, int _T) {
        memset(dep, 0, sizeof(dep));
        queue <int> q; q.push(_S); dep[_S] = 1;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(int i = head[u]; ~i; i = e[i].next) {
                int v = e[i].v;
                if(!dep[v] && e[i].flow > 0) {
                    dep[v] = dep[u] + 1;
                    q.push(v);
                }
            }
        }
        return dep[_T] != 0;
    }
    T dfs(int _S, int _T, T a) {
        T flow = 0, f;
        if(_S == _T || a == 0) return a;
        for(int i = head[_S]; ~i; i = e[i].next) {
            int v = e[i].v;
            if(dep[v] != dep[_S] + 1) continue;
            f = dfs(v, _T, min(a, e[i].flow));
            if(f) {
                e[i].flow -= f;
                e[i ^ 1].flow += f;
                flow += f;
                a -= f;
                if(a == 0) break;
            }
        }
        if(!flow) dep[_S] = -1;
        return flow;
    }
    T dinic(int _S, int _T) {
        T max_flow = 0;
        while(BFS(_S, _T)) max_flow += dfs(_S, _T, INF);
        return max_flow;
    }
    bool chk[N * N], vis[N * N];
    int ans;
    void go(int u, int d) {
        vis[u] = 1;
        if(u >= 1 && u <= tot) {
            if(col[u] == d) ++ans, chk[u] = 1;
        }
        for(int i = head[u]; i != -1; i = e[i].next) {
            int v = e[i].v;
            if(!vis[v] && e[i ^ (1 - d)].flow > 0) go(v, d);
        }
    }
    void print() {
        if(ans) cout << "WIN" << '\n';
        else cout << "LOSE" << '\n';
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(mp[i][j] && chk[mp[i][j]]) cout << i << ' ' << j << '\n';  
            }
        }
    }
};

Dinic <int> solver;

const int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, 1, -1};
bool ok(int x, int y) {
    return x >= 1 && y >= 1 && x <= n && y <= m && mp[x][y] && (x + y) % 2 == 0;
}
void run() {
    solver.init();
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> (s + 1);
        for(int j = 1; j <= m; j++) {
            if(s[j] == '.') mp[i][j] = ++tot;
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(i + j & 1 && mp[i][j]) {
                for(int k = 0; k < 4; k++) {
                    int nx = i + dx[k], ny = j + dy[k];
                    if(ok(nx, ny)) solver.adde(mp[i][j], mp[nx][ny], 1);
                }
            }
        }
    }
    int S = 0, T = tot + 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) if(mp[i][j]) {
            if(i + j & 1) solver.adde(S, mp[i][j], 1), col[mp[i][j]] = 1;
            else solver.adde(mp[i][j], T, 1);
        }
    }
    solver.dinic(S, T);
    solver.go(S, 1); solver.go(T, 0);
    solver.print(); 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
	return 0;
}

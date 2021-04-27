// Author : heyuhhh
// Created Time : 2021/03/07 09:21:06
#include<bits/stdc++.h>
#define MP make_pair
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//head
const int N = 1e5 + 5;
#define INF 0x3f3f3f3f
template <class T>
struct Dinic{
    struct Edge{
        int v, next;
        T flow;
        Edge(){}
        Edge(int v, int next, T flow) : v(v), next(next), flow(flow) {}
    }e[N << 1];
    int head[N], tot;
    int dep[N];
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
};
Dinic<int> solver;
void run() {
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    solver.init();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            int u = i * n + j, v = i * n + j + 1;
            solver.adde(u, v, 1);
            solver.adde(v, u, 1);
        }
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n; j++) {
            int u = i * n + j, v = i * n + j + n;
            solver.adde(u, v, 1);
            solver.adde(v, u, 1);
        }
    }
    int S = n * n, T = n * n + 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] == '?') {
                continue;
            }
            if ((i + j) & 1) {
                s[i][j] = (s[i][j] == 'B' ? 'W' : 'B');
            }
            if (s[i][j] == 'B') {
                solver.adde(S, i * n + j, INF);
            } else {
                solver.adde(i * n + j, T, INF);
            }
        }
    }
    int ans = 2 * n * (n - 1) - solver.dinic(S, T);
    cout << ans << '\n';
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
// Author : heyuhhh
// Created Time : 2020/08/22 20:15:43
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
const int N = 1e6 + 5, M = 1e7 + 5;

struct Edge{
    int v, w, next;   
}e[M << 1];
int dis[N];
struct Dijkstra{
    struct node{
        int d, u;
        bool operator < (const node &A) const {
            return d > A.d;
        }   
    };
    int head[N], tot;
    bool vis[N];
    void init() {
        memset(head, -1, sizeof(head)); tot = 0;   
    }
    void adde(int u, int v, int w) {
        e[tot].v = v; e[tot].w = w; e[tot].next = head[u]; head[u] = tot++;   
    }
    void dij(int s) {
        priority_queue <node> q;
        memset(dis, INF, sizeof(dis));
        memset(vis, 0, sizeof(vis));
        dis[s] = 0;
        q.push(node{0, s});
        while(!q.empty()) {
            node cur = q.top(); q.pop();
            int u = cur.u, d = cur.d;
            if(vis[u]) continue;
            vis[u] = 1;
            for(int i = head[u]; i != -1; i = e[i].next) {
                int v = e[i].v;
                if(dis[v] > dis[u] + e[i].w) {
                    dis[v] = dis[u] + e[i].w;
                    q.push(node{dis[v], v});   
                }
            }   
        }
    }
}solver;

void run() {
    int n, m;
    cin >> n >> m;
    int sx, sy;
    int ex, ey;
    cin >> sx >> sy >> ex >> ey;
    --sx, --ex, --sy, --ey;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    vector<vector<bool>> vis(n, vector<bool>(m));
    vector<vector<int>> bel(n, vector<int>(m));
    static int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
    auto ok = [&] (int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m && s[x][y] == '.' && !vis[x][y];
    };
    int cnt = 0;
    function<void(int, int)> dfs = [&] (int x, int y) {
        vis[x][y] = 1;
        bel[x][y] = cnt;
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (ok(nx, ny)) {
                dfs(nx, ny);
            }
        }
    };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '.' && !vis[i][j]) {
                ++cnt;
                dfs(i, j);
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            vis[i][j] = 0;
        }
    }
    map<int, map<int, int>> mp;
    solver.init();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '.') {
                for (int t = -2; t <= 2; t++) {
                    for (int q = -2; q <= 2; q++) {
                        int nx = i + t, ny = j + q;
                        if (ok(nx, ny) && bel[i][j] != bel[nx][ny]) {
                            if (mp[bel[nx][ny]][bel[i][j]] > 0) continue;
                            solver.adde(bel[i][j], bel[nx][ny], 1);
                            solver.adde(bel[nx][ny], bel[i][j], 1);
                            mp[bel[nx][ny]][bel[i][j]] = mp[bel[i][j]][bel[nx][ny]] = 1;
                        }
                    }
                }
            }
        }
    }
    solver.dij(bel[sx][sy]);
    
    int ans = dis[bel[ex][ey]];
    if (ans == INF) ans = -1;
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
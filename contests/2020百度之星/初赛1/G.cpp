// Author : heyuhhh
// Created Time : 2020/07/19 16:02:29
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
const int N = 1e3 + 5;

int n, m, k;

ll dis[N][N];
struct Dijkstra{
    struct node{
        ll d;
        pii u;
        bool operator < (const node &A) const {
            return d > A.d;
        }   
    };
    bool vis[N][N];
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    bool ok(int x, int y) {
        return 1 <= x && x <= n && 1 <= y && y <= m;
    }
    void dij(int sx, int sy) {
        priority_queue <node> q;
        memset(dis, INF, sizeof(dis));
        memset(vis, 0, sizeof(vis));
        dis[sx][sy] = 0;
        q.push(node{0, MP(sx, sy)});
        while(!q.empty()) {
            node cur = q.top(); q.pop();
            pii u = cur.u;
            int d = cur.d;
            int x = u.fi, y = u.se;
            if(vis[x][y]) continue;
            vis[x][y] = 1;
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (!ok(nx, ny)) continue;
                if (dis[nx][ny] > dis[x][y] + 1) {
                    dis[nx][ny] = dis[x][y] + 1;
                    q.push(node{dis[nx][ny], MP(nx, ny)});
                }
            }
        }
    }
}solver;

int d[7][N][N];

void run() {
    cin >> n >> m >> k;
    int all = 0;
    for (int i = 1; i <= k; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        all += z;
        solver.dij(x, y);
        for (int j = 1; j <= n; j++) {
            for (int t = 1; t <= m; t++) {
                d[i][j][t] = dis[j][t];
            }
        }
    }
    if (all < n * m) {
        cout << -1 << '\n';
        return;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int res = INF;
            for (int p = 1; p <= k; p++) {
                res = min(res, d[p][i][j]);
            }
            ans = max(ans, res);
        }
    }
    cout << ans << '\n';
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T; while(T--)
    run();
    return 0;
}
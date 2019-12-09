int a[N][N];
int n, m;
#define mp make_pair
#define se second
#define fi first
namespace max_matrix{
    int vis[N], f[N], sz[N];
    int t[N][N];
    int mx = 0, mx2 = 0;
    pair<int, int> h[N];
    int find(int x) {
        return f[x] == x ? x : f[x] = find(f[x]) ;
    }
    void Union(int x, int y) {
        int fx = find(x), fy = find(y);
        f[fx] = fy;
        sz[fy] += sz[fx];
    }
    void solve(int a, int b) {
        int area = a * b;
        if(area > mx) mx2 = mx, mx = area;
        else if(area > mx2) mx2 = area;
    }
    int work(int n, int m, int a[][N]) {
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++) {
                t[i][j] = (a[i][j] == 1) ? t[i - 1][j] + 1 : 0;
            }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                f[j] = j, vis[j] = 0, h[j] = mp(t[i][j], j), sz[j] = 1;
            }
            sort(h + 1, h + m + 1);
            for(int j = m; j >= 1; j--) {
                int k = h[j].se; vis[k] = 1;
                if(vis[k - 1]) Union(k - 1, k);
                if(vis[k + 1]) Union(k + 1, k);
                int len = sz[find(k)];
                solve(len, h[j].fi);
                solve(len - 1, h[j].fi);
                solve(len, h[j].fi - 1);
            }
        }
        return mx2;
    }
}; 

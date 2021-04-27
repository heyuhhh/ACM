#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, k;
int a[1010][1010];
int cnt[510][110], f[510][110];
vector<int> son[510];
bool vis[510];
int col[510];
int x[510], y[510], z[510], w[510];

void dfs(int i, int fa) {
    col[i] = 3 - col[fa];
    for (auto it : son[i]) {
        if(it == fa) continue;
        if(col[it]) {
            if(col[it] == col[i]) {
                cout << -1 << '\n';
                exit(0);
            }
            continue;    
        };
        dfs(it, i);
    }
}
int dfs2(int u, int fa, int i, int j, int step) {
    vis[u] = 1;
    int tmp;
    if(step == 1) tmp = f[u][i];
    else tmp = f[u][j];
    for (auto it : son[u]) {
        if(it == fa) continue;
        if(!vis[it]) tmp += dfs2(it, u, i, j, 1 - step);
    }
    return tmp;
}
void dfs3(int u, int fa) {
    vis[u] = 0;
    for (auto it : son[u]) {
        if(it == fa) continue;
        if(vis[it]) dfs3(it, u); 
    }
}
void run() {
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) {
        cin >> x[i] >> y[i] >> z[i] >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= k; i++) {
        for (int xx = x[i]; xx <= z[i]; xx++) {
            for (int yy = y[i]; yy <= w[i]; yy++) {
                cnt[i][a[xx][yy]]++;
                f[i][0] += a[xx][yy];
            }
        }
        for (int j = i + 1; j <= k; j++) {
			int sl=max(x[i],x[j]),ml=min(z[i],z[j]);
			int sh=max(y[i],y[j]),mh=min(w[i],w[j]);
			if(sl-1<=ml && sh-1<=mh){
				son[i].push_back(j);
				son[j].push_back(i);
			}            
        }
    }
    col[0] = 1;
    for (int i = 1; i <= k; i++) if(!col[i]) {
        dfs(i, 0);
    }
    for (int i = 1; i <= k; i++) {
        int num = (z[i] - x[i] + 1) * (w[i] - y[i] + 1), tmp = 0;
        for (int j = 1; j <= 100; j++) {
            f[i][j] = f[i][j - 1] - num + tmp;
            num -= cnt[i][j];
            tmp += cnt[i][j];
        }
    }
    int ans = 1e9 + 7;
    for (int i = 1; i <= 100; i++) {
        for (int j = i + 1; j <= 100; j++) {
            int tmp = 0, tmp2;
            for (int fff = 1; fff <= k; fff++) vis[fff] = 0;
            for (int fff = 1; fff <= k; fff++) if(!vis[fff]) {
                tmp2 = dfs2(fff, 0, i, j, 1);
                dfs3(fff, 0);
                tmp2 = min(tmp2, dfs2(fff, 0, i, j, 0));
                tmp += tmp2;
            }
            ans = min(ans, tmp);
        }
    }
    cout << ans << endl;
}
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(10);
    //int T = 1; cin >> T; while (T--)
    run();
}
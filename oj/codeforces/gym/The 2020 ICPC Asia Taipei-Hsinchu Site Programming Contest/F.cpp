#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAXN = int(2e5)+7;

int hd[MAXN*2], to[MAXN*4], nxt[MAXN*4], en;

inline void adde(int a, int b) {
	nxt[en]=hd[a]; to[en]=b; hd[a]=en; en++;
}

int dp1[MAXN+MAXN][2], dp2[MAXN*2][2];
int id[MAXN*2];
int n,m;
void dfs(int x, int fa) {
	dp1[x][0]=0;
	dp1[x][1]=1;
	for(int i=hd[x]; ~i; i=nxt[i]) {
		int y=to[i];
		if(y==fa || y<n) {
			continue;
		}
		dfs(y,x);
		dp1[x][0]+=dp1[y][1];
		dp1[x][1]+=min(dp1[y][1], dp1[y][0]);
	}
}
void run() {
	cin >> n >> m;
	en=0;
	memset(hd,-1,sizeof hd);
	memset(dp1,0,sizeof dp1);
    vector<vector<int>> G(n+m-1);
	for(int i=0; i<n+m; i++) {
		int a,b; cin >> a >> b;
        if (a < n && b < n) {
            G[a].emplace_back(b);
            G[b].emplace_back(a);
        } else {
            adde(a,b), adde(b,a);
        }
	}

    int tot = 0;
    vector<bool> vis(n + m - 1);
    function<void(int)> work = [&] (int u) {
        vis[u] = true;
        id[tot++] = u;
        for (auto v : G[u]) if (v < n && !vis[v]) {
            work(v);
        }
    };
    work(0);
    // for (int i = 0; i < tot; i++) {
    //     cout << id[i] << endl;
    // }

	for(int i=0; i<n+m-1; i++) if (i < n) {
		dfs(i, -1);
	}
	int ans=0x3f3f3f3f;
    {
        memset(dp2, INF, sizeof(dp2));
        dp2[id[0]][0] = dp1[id[0]][0];
        for (int i = 1; i < n; i++) {
            dp2[id[i]][0] = dp2[id[i - 1]][1] + dp1[id[i]][0];
            dp2[id[i]][1] = min(dp2[id[i - 1]][0], dp2[id[i - 1]][1]) + dp1[id[i]][1];
        }
        ans = dp2[id[n - 1]][1];
    }
    {
        memset(dp2, INF, sizeof(dp2));
        dp2[id[0]][1] = dp1[id[0]][1];
        for (int i = 1; i < n; i++) {
            dp2[id[i]][0] = dp2[id[i - 1]][1] + dp1[id[i]][0];
            dp2[id[i]][1] = min(dp2[id[i - 1]][0], dp2[id[i - 1]][1]) + dp1[id[i]][1];
        }
        ans = min(ans, min(dp2[id[n - 1]][1], dp2[id[n - 1]][0]));
    }
	cout << ans << endl;
}

int main() {
#ifdef Local
	freopen("input.in", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(20);
	//int T; cin >> T; while (T--)
	run();
	return 0;
}

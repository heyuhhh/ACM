#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e5 + 5;

int n, m;
int mp[1010][1010];
int dfn[1010], low[1010], vis[1010], step;
int cut[1010], num[1010], colnum;
int point, edge;
int fz, fm;
void Tarjan(int u,int pre){
    dfn[u]=low[u]=++step;
    int son=0;
    for (int v = 1; v <= n; v++) if(mp[u][v] && v != pre){
        if(!dfn[v]){
            son++;//起点有效儿子
            Tarjan(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>=dfn[u] && pre)cut[u]=1,point++;
            if(low[v]>dfn[u]){
                edge++;
            }
        }else{
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(!pre && son>1) cut[u]=1, point++;
}

void run() {
	cin >> n >> m;
	int u, v;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v;
		mp[u][v] = 1;
		mp[v][u] = 1;
	}
	Tarjan(1, 0);
	if(edge) fm = 1;
	for (int i = 1; i <= n; i++) {
		if(!vis[low[i]]) {
			colnum++;
			vis[low[i]] = 1;
		}
		for (int j = i + 1; j <= n; j++) {
			if(mp[i][j]) {
				if(low[i] == low[j]) num[low[i]]++;
				if(num[low[i]] > fm) fm = num[low[i]];
			}
		}
	}
	fz = colnum + edge;
	cout << point << ' ' << edge << ' ' << fz / __gcd(fz, fm) << ' ' << fm / __gcd(fz, fm) << endl;
	for (int  i = 1; i <= n; i++) {
		dfn[i] = low[i] = cut[i] = num[i] = vis[i] = 0;
		for (int j = 1; j <= n; j++) mp[i][j] = 0;
	}
	step = fz = fm = point = edge = colnum = 0;
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(20);
	int T; cin >> T; while (T--)
	run();
	return 0;
}


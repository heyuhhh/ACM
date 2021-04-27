#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = int(1e5)+7;
const int MAXM = int(2e5)+7;
const int MAXS = int(1e6)+7;

struct LOG {
	int t,x,y;
};

LOG logs[MAXS*2];
LOG quns[MAXS]; int qunn=0;
int summsg[MAXN];
int ans[MAXM];

inline bool cmp1(const LOG&a, const LOG&b) {
	if(a.x!=b.x) return a.x<b.x;
	if(a.y!=b.y) return a.y<b.y;
	return a.t<b.t;
}

void run() {
	int n,m,s; cin >> n >> m >> s;
	
	for(int i=0; i<s; i++) {
		cin >> logs[i].t >> logs[i].x >> logs[i].y;
	}
	for(int i=0; i<s; i++) {
		if(logs[i].t==1 || logs[i].t==2) {
			quns[qunn++]=logs[i];
		}
	}
	sort(quns,quns+qunn,cmp1);
	quns[qunn].x=-1, quns[qunn].y=-1;
	for(int i=0,lstx=-1,lsty=-1,cntt=0; i<=qunn; i++) {
		if(quns[i].x!=lstx || quns[i].y!=lsty) {
			if(cntt!=0) {
				logs[s].x=lstx;
				logs[s].y=lsty;
				logs[s].t=2;
				s++;
			}
			lstx=quns[i].x;
			lsty=quns[i].y;
			cntt=1;
		} else {
			if(quns[i].t==1) cntt++;
			else cntt--;
		}
	}
	memset(summsg,0,sizeof summsg);
	memset(ans,0,sizeof ans);
	
	for(int i=0; i<s; i++) {
//		cerr << logs[i].t << '\t' << logs[i].x << '\t' << logs[i].y << '\n';
		if(logs[i].t==1) {
			ans[logs[i].x]-=summsg[logs[i].y];
		} else if(logs[i].t==2) {
			ans[logs[i].x]+=summsg[logs[i].y];
		} else if(logs[i].t==3) {
			ans[logs[i].x]--;
			summsg[logs[i].y]++;
		}
	}
	for(int i=1; i<=m; i++) {
		cout << ans[i] << '\n';
	}
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(20);
	//int T; cin >> T; while (T--)
	run();
	return 0;
}


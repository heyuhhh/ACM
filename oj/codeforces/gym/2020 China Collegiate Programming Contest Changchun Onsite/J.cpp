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

const int MO=int(1e9)+7;

const int MAXL = 10;
const int MAXR = 5;
int cnt[MAXR+7][MAXL+7];

int dfs(int x, int mx, int mr) {
	int ans=0;
	for(int i=1; i<mr; i++) {
		if(x+i<=mx && x+i+i<=mr+mr) ans=(ans+((dfs(x+i+i,mx,mr)+1ll)*cnt[i][min(i+i,mx-x)])%MO)%MO;
	}
	if(x+1<mx) ans=(ans+dfs(x+1,mx,mr))%MO;
	return ans;
}

void db() {
	for(int r=1; r<=5; r++) {
		for(int l=r; l<=r+r; l++) {
			cnt[r][l]=(dfs(0,l,r)+1)%MO;
		}
	}
}

void run() {
	db();
	int n,k; cin >> n >> k;
	for(int i=0; i<k; i++) {
		
	}
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(20);
//	int T; cin >> T; while (T--)
	run();
	return 0;
}


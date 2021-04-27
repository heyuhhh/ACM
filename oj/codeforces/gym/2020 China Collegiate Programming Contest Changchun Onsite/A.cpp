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

const int pri[]={1,6,28,88,198,328,648};
const int re[]={8,18,28,58,128,198,388};
int dp[2007];
void run() {
	
	int n; cin >> n;
	int ans=n*10;
	for(int i=0; i<7; i++) {
		for(int j=n; j>=pri[i]; j--) {
			dp[j]=max(dp[j],dp[j-pri[i]]+re[i]);
		}
	}
	cout << ans+dp[n] << '\n';

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


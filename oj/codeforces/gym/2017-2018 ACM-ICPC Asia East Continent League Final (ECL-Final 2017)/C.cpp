#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXA = 100007;
ll l[MAXA];
void run() {
	int n; cin >> n;
	ll ans=0;
	for(int i=0; i<=n; i++) {
		int t; cin >> t;
		ans+=t;
	}
	int mx=0;
	for(int i=0; i<n; i++) {
		int t; cin >> t; cin>>t;
		mx=max(mx, t);
	}
	ans+=mx;
	cout << ans << ".00000000" << '\n';
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	for(int kase=1; kase<=t; kase++) {
		cout << "Case #" << kase << ": ";
		run();
	}
	return 0;
}


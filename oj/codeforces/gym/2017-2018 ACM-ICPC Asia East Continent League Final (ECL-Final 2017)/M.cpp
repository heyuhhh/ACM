#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void run() {
	int a[5]; for(int i=0; i<5; i++) cin >> a[i];
	int n; cin >> n;
		int ans=0;
	for(int i=0; i<n; i++) {
		int t; cin >> t;
		switch(t) {
			case 1 ... 48:
				ans+=a[0];break;
			case 49 ... 56:
				ans+=a[1];break;
			case 57 ... 60:
				ans+=a[2];break;
			case 61 ... 62:
				ans+=a[3];break;
			case 63:
				ans+=a[4];break;
		}
	}
		cout << ans << "0000\n";
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


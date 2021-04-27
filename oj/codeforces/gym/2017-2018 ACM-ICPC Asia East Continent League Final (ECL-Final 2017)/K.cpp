#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXA = 100007;
ll l[MAXA];
void run() {
	int a,b,n; cin >> a >> b >> n;
	l[0]=0;
	for(int i=1; i<=a; i++) cin >> l[i];
	for(int i=2; i<=a; i++) l[i]+=l[i-1];
	for(int i=1; i<=n; i++) {
		int t=a;
		int a_=lower_bound(l, l+a+1, t)-l;
		int b_=t-l[a_-1];
		if(a==a_ && b==b_)  {
			break;
		}
		a=a_, b=b_;
	}
	cout << a << '-' << b << '\n';
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


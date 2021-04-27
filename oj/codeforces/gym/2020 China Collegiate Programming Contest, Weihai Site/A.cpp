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

void run() {
	int n, x, t;
	cin >> n >> t >> x; 
	ll End = 2ll * n * x;
	ll resL = 2ll * (n - 1) * x, resR = End;
	ll ans = 9e18;
	if (resL >= t) ans = min(ans, 2ll * End);
	else ans = min(ans, t - resL + 2ll * End);
	
	if(resR >= t) ans = min(ans, 2ll * End + x);
	else ans = min(ans, t - resR + x + 2ll * End);
	cout << ans << '\n';
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


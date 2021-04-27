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

ll id, x, y;
ll ansx, ansy;
void solve1() {
	cin >> id;
	if(id == 0) {
		cout << -x << ' ' << -y << '\n';
		x = y = 0;
		return;
	}
	ll l = 1, r = 1e8;
	while(l < r) {
		ll mid = (l + r + 1) >> 1;
		if(2 * mid * (mid - 1) >= id) r = mid - 1;
		else l = mid;
	}
	id -= 2 * l * (l - 1);
	if(id < 2 * l) {
		if(id & 1) {
			ansx = -id / 2;
			ansy = l + ansx;
		}
		else {
			ansx = id / 2;
			ansy = l - ansx;
		}
	}
	else {
		if(id <= 3 * l) {
			ansy = 2 * l - id;
			ansx = l + ansy;
		}
		else {
			ansx = 3 * l - id;
			ansy = -l - ansx;
		}
	}
	cout << ansx - x << ' ' << ansy - y << '\n';
	x = ansx, y = ansy;
}
void solve2() {
	cin >> x >> y;
	if(x == 0 && y == 0) {
		cout << 0 << '\n';
		return;
	}
	if(x > 0 && y > 0) id = 2 * x;
	else if(x <= 0 && y > 0) id = - 2 * x + 1;
	else if(x >=0 && y <= 0) id = 2 * x - 3 * y;
	else id = - 4 * x - 3 * y;
	ll l = abs(x) + abs(y);
	cout << id + 2 * l * (l - 1) << '\n';

}


void run() {
	int tmp;
	cin >> tmp;
	if(tmp == 1) solve1();
	else solve2();

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


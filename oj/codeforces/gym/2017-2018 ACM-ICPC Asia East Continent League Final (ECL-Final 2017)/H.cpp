#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char s[1000010];
int x, y, n;
bool flag;
pair<int, int> a[1000010]; 
void run() {
	cin >> s;
	cin >> x >> y;
	n = 0;
	a[0].first = -1;
	int cnt;
	for (int i = 0; s[i] != 0; i++) {
		if(s[i] == '?') cnt = 2;
		else if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') cnt = 1;
		else cnt = 0;
		if(cnt != a[n].first) {
			a[++n].first = cnt;
			a[n].second = 0;
		}
		a[n].second++;
	}
	cnt = 0;
	flag = 0;
	if(x == 1) {
		for (int i = 1; i <= n; i++) {
			cnt += a[i].second;
			if(a[i].first == 1 || cnt >= y) {
				cout << "DISLIKE" << endl;
				return;
			}
			if(a[i].first == 2) flag = 1;
		}
		if(flag) cout << "SURPRISE" << endl;
		else cout << "LIKE" << endl;
		return;
	}
	if(y == 1) {
		for (int i = 1; i <= n; i++) {
			cnt += a[i].second;
			if(a[i].first == 0 || cnt >= x) {
				cout << "DISLIKE" << endl;
				return;
			}
			if(a[i].first == 2) flag = 1;
		}
		if(flag) cout << "SURPRISE" << endl;
		else cout << "LIKE" << endl;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if(a[i].first) cnt += a[i].second;
		else cnt = 0;
		if(cnt >= x) flag = 1;
	}
	if(!flag) {
		cnt = 0;
		for (int i = 1; i <= n; i++) {
			if(a[i].first != 1) cnt += a[i].second;
			else cnt = 0;
			if(cnt >= y) flag = 1;
		}
	}
	if(!flag) {
		cout << "LIKE" << endl;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if(a[i].first == 2) {
			if(i == 1 || i == n) continue;
			if(a[i - 1].first == a[i + 1].first) {
				if(a[i].second & 1) {
					continue;
				}
				if(x == 2 && y == 2) {
					flag = 0;
					break;
				}
			}
			else {
				if(a[i].second % 2 == 0) {
					continue;
				}
				if(x == 2) {
					if(a[i - 1].first == 0) {
						if(a[i - 1].second + 1 == y) {
							flag = 0;
							break;
						}
					}
					else {
						a[i + 1].second++;
					}
				}
				else if(y == 2) {
					if(a[i - 1].first == 1) {
						if(a[i - 1].second + 1 == x) {
							flag = 0;
							break;
						}
					}
					else {
						a[i + 1].second++;
					}
				}
				else if(a[i].second == 1) {
					if(a[i - 1].first == 1) {
						if(a[i - 1].second + 1 == x) {
							a[i + 1].second++;
						}
					}
					if(a[i - 1].first == 0) {
						if(a[i - 1].second + 1 == y) {
							a[i + 1].second++;
						}
					}
				}
			}
		}
		else if(a[i].first == 1 && a[i].second >= x) {
			flag = 0;
			break;
		}
		else if(a[i].first == 0 && a[i].second >= y) {
			flag = 0;
			break;
		}
	}
	if(flag) cout << "SURPRISE" << endl;
	else cout << "DISLIKE" << endl;
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T; cin >>T;
	for (int i = 1; i <= T; i++) {
		cout << "Case #" << i << ": ";
		run();
	}
	return 0;
}


#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
 
void run() {
	int k, x;
	cin >> k >> x;
	int up = k;
	// 0...k - 1
	int all = 0;
	ll res = k;
	int len;
	for (int i = 1;; i++) {
		if (all + res < x) {
			all += res;
			res *= k;
		} else {
			len = i;
			break;
		}
	}
	vector<int> ans;
	for (int j = 0; j < len; j++) {
		res /= k;
		for (int i = 0; i < up; i++) {
			if (all + res < x) {
				all += res;
			} else {
				ans.emplace_back(i);
				break;
			}
 
		}
	}
	for (int i = 0; i < len; i++) {
		cout << ans[i] + 10 - k;
	}
	cout << '\n';
}
 
int main() {
	cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
	int T; cin >> T;
	while (T--) run();
}
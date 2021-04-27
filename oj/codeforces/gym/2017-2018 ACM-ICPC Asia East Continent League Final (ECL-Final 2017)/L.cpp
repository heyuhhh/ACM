#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int _;
void run() {
	++_;
	int n;
	cin >> n;
	cout << "Case #" << _ << ": ";
	if (n >= 7 && n & 1) {
		cout << "Panda" << '\n';
		return;
	}
	if (n >= 16 && n % 2 == 0) {
		cout << "Sheep" << '\n';
		return;
	}
	cout << "Draw" << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T; cin >> T; while (T--)
	run();
	return 0;
}


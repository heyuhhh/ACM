#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int n;
ll a[200010];
ll d[200010];
void run() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	a[n + 1] = 0;
	queue<int> he, ta;
	for (int i = 1; i <= n + 1; i++) {
		d[i] = a[i] - a[i - 1];
		if(d[i] > 0) he.push(i);
		if(d[i] < 0) ta.push(i);
	}
	int head = he.front(), tail = ta.front();
	he.pop(); ta.pop();
	while(head + 3 <= tail) {
		if(d[head] + d[tail] > 0) {
			d[head] += d[tail];
			d[tail] = 0;
			tail = ta.front();
			ta.pop();
		}
		else if(d[head] + d[tail] < 0) {
			d[tail] += d[head];
			d[head] = 0;
			head = he.front();
			he.pop();
		}
		else {
			if(he.empty() || ta.empty()) {
				cout << "Yes" << endl;
				return;
			}
			tail = ta.front();
			ta.pop();
			head = he.front();
			he.pop();
		}
	}
	cout << "No" << endl;
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T; cin >> T; 
	for (int i = 1; i <= T; i++) {
		cout << "Case #" << i << ": ";
		run();
	}
	
	return 0;
}


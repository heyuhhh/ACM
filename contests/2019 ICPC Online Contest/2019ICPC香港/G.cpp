#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
 
void run() {
	int k;
	cin >> k;
	int high;
	for (int i = 30; i >= 0; i--) {
		if (k >> i & 1) {
			high = i;
			break;
		}
	}
	vector<int> f(2);
	vector<int> c(2);
	int tot = 2;
	auto new_node = [&] (int fa, int v) {
		++tot;
		f.emplace_back(fa);
		c.emplace_back(v);
	};
	int rt = 2;
	f.emplace_back(-1);
	c.emplace_back(1000000000);
	new_node(rt, 1);
 
	int sons = 1;
	for (int i = high - 1; i >= 0; i--) {
		new_node(rt, 1);
		new_node(tot, 1);
		++sons;
		if (k >> i & 1) {
			new_node(-1, sons);
			f[rt] = tot;
			rt = tot;
			
			new_node(-1, 1000000000);
			f[rt] = tot;
			rt = tot;
		} 
	}
	f[rt] = 1;
	c[1] = 1000000000;
 
	cout << tot << '\n';
	for (int i = 2; i <= tot; i++) {
		cout << f[i] << " \n"[i == tot];
	}
	for (int i = 1; i <= tot; i++) {
		cout << c[i] << " \n"[i == tot];
	}
}
 
int main() {
	cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
	run();
}
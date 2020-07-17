#include <bits/stdc++.h>
#define out	freopen("data.txt", "w", stdout);
using namespace std;
typedef long long ll;
ll fac[100000];
mt19937 rnd(time(NULL));
ll rand(ll x) {
	return (rnd() % x) + 1;
}
int a[1000000];
int main() {
	out
	int T = 5;
	while (T--) {
		int n = rand(1000);
		cout << n << '\n';
		for (int i = 1; i <= n; i++) {
			int x = rand(2);
			if (x & 1) cout << 'a';
			else cout << 'b';	
		}
		cout << '\n';
	}
	return 0;
}
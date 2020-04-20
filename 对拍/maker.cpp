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
	//out
	int n = rand(1000000000), m = rand(100);
	cout << n << ' ' << m;
	return 0;
}

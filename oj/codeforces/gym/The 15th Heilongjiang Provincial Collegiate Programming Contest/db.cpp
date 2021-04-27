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
vector<unsigned long long> mp;

void run() {
	unsigned long long i=1, n3, i3=1;
	unsigned long long s=i3;
	for(int j=0; j<4194303; j++) {
		mp.push_back(i3);
		i++; i3=i*i*i;
	}
	cout << mp.size() << '\n';

}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(20);
	//int T; cin >> T; while (T--)
	run();
	return 0;
}


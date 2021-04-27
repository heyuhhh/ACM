#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;

const int MAXN=int(1e6)+7;
int seg[MAXN<<2];
int a[MAXN];
int c;
int n;

int V, L, R;
inline void _opa(int p, int l, int r) {
	if(l==r && l==L) {
		seg[p]-=V;
		return;
	}
	int m=(l+r)>>1;
	if(L<=m) {
		_opa(p*2, l,m);
	} else {
		_opa(p*2+1, m+1,r);
	}
	seg[p]=max(seg[p*2], seg[p*2+1]);
}
inline void opa(int pos, int val) {
	L=pos;
	V=val;
	_opa(1,1,n);
}

inline int opq(int p, int l, int r) {
	if(l==r) {
		if(seg[p]>=V) return l;
		else return -1;
	}
	int m=(l+r)/2;
	if(seg[p*2]>=V) {
		return opq(p*2, l, m);
	} else {
		return opq(p*2+1, m+1, r);
	}
}

inline void opr(int p, int l, int r) {
		seg[p]=c;
	if(l==r) {
		return;
	}
	int m=(l+r)/2;
	opr(p*2, l, m);
	opr(p*2+1, m+1,r);
}


void run() {
	cin >> n >> c;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	opr(1,1,n);
	int ans=0;
	for(int i=1; i<=n; i++) {
		V=a[i];
		int t=opq(1,1,n);
		assert(t!=-1);
		ans=max(ans, t);
		opa(t,a[i]);
	}
	
	cout << ans << ' ';
	
	multiset<int> ms;
	for(int i=1; i<=n; i++) {
		auto it=ms.lower_bound(a[i]);
		if(it!=ms.end()) {
			int nv=*it-a[i];
			ms.erase(it);
			ms.insert(nv);
		} else {
			ms.insert(c-a[i]);
		}
	}
	cout << ms.size() << '\n';
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


/*
 * Author:  heyuhhh
 * Created Time:  2020/4/8 16:53:53
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <assert.h>
#pragma GCC optimize(2)
#define MP make_pair
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//head
const int N = 4e6 + 5, M = (1 << 19);
const double pi = acos(-1.0);
#define ri register int
#define cs const
struct C {
	double x, y;
	C(double xx = 0, double yy = 0) { x = xx, y = yy; };
};
C operator + (C a, C b) { return C(a.x + b.x, a.y + b.y); }
C operator - (C a, C b) { return C(a.x - b.x, a.y - b.y); }
C operator * (C a, C b) { return C(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x); }
typedef vector<C> Poly;
int rev[N];     
inline void init_rev(int len) {
    for(ri i = 0; i < len; i++) rev[i] = rev[i >> 1] >> 1 | ((i & 1) * (len >> 1));   
}
void FFT(Poly &A, int limit, int type) {
	for(ri i = 0; i < limit; i++) if(i < rev[i]) swap(A[i], A[rev[i]]);
	for(ri i = 1; i < limit; i <<= 1) {
		C Wn(cos(pi / i), type * sin(pi / i));
		for (int j = 0; j < limit; j += (i<<1)) {
			C w(1, 0);
			for (int k = 0; k < i; k++, w = w * Wn) {
				C x = A[j + k], y = w * A[j + k + i];
				A[j + k] = x + y;
				A[j + k + i] = x - y;	
			}
		}
	}
    if(type == -1) for(int i = 0; i < limit; i++) A[i].x /= limit, A[i].x += 0.5;
}

inline Poly operator * (Poly a, Poly b) {
    int n = sz(a), m = sz(b), l = 1;
    while(l < n + m - 1) l <<= 1;
    init_rev(l);
    a.resize(l), FFT(a, l, 1);
    b.resize(l), FFT(b, l, 1);
    for(ri i = 0; i < l; i++) a[i] = a[i] * b[i];
    FFT(a, l, -1);
    a.resize(n + m - 1);
    return a;
}
void run() {
    int n, m; cin >> n >> m;
    vector <int> a(n), b(n);
    Poly x(n), y(n << 1);
    for(ri i = 0; i < n; i++) cin >> a[i], x[i] = C(a[i]);
    for(ri i = 0; i < n; i++) cin >> b[i], y[i] = y[i + n] = C(b[i]);
    reverse(all(y));
    ll ans = 1e18;
    for(ri d = 0; d < m; d++) {
        if(d) for(int i = 0; i < n; i++) x[i].x += 1, ++a[i];
        ll res = 0;
        for(ri i = 0; i < n; i++) res += 1ll * a[i] * a[i] + 1ll * b[i] * b[i];
        Poly c = x * y;
        ll Min = 1e18;
        for(ri i = n; i < n << 1; i++) Min = min(Min, -2 * (ll)(c[i].x));
        res += Min;
        if(res < ans) ans = res;   
        else break;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}

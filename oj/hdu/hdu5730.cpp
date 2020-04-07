/*
 * Author:  heyuhhh
 * Created Time:  2020/4/7 8:19:31
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <assert.h>
#define MP make_pair
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
#define Local
#ifdef Local
  #define dbg(args...) do { cout << #args << " -> "; err(args); } while (0)
  void err() { std::cout << '\n'; }
  template<typename T, typename...Args>
  void err(T a, Args...args) { std::cout << a << ' '; err(args...); }
  template <template<typename...> class T, typename t, typename... A> 
  void err(const T <t> &arg, const A&... args) {
  for (auto &v : arg) std::cout << v << ' '; err(args...); }
#else
  #define dbg(...)
#endif
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//head
const int N = 4e5 + 5, MOD = 313;
const double pi = acos(-1.0);
struct C{
    double x, y;
    C (double xx = 0, double yy = 0) {x = xx, y = yy;}
}a[N], b[N];
C operator + (C a, C b) {return C(a.x + b.x, a.y + b.y);}
C operator - (C a, C b) {return C(a.x - b.x, a.y - b.y);}
C operator * (C a, C b) {return C(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);}
int r[N];
void FFT(C *A, int type, int n) {
    for(int i = 0; i < n; i++) if(i < r[i]) swap(A[i], A[r[i]]);
    for(int mid = 1; mid < n; mid <<= 1) {
        C Wn(cos(pi / mid), type * sin(pi / mid)) ;
        for(int R = mid << 1, j = 0; j < n; j += R) {
            C w(1, 0);
            for(int k = 0; k < mid; k++, w = w * Wn) {
                C x = A[j + k], y = w * A[j + mid + k];
                A[j + k] = x + y;
                A[j + mid + k] = x - y;
            }
        }
    }
    if(type == -1) {
        for(int i = 0; i < n; i++) A[i].x = A[i].x / n + 0.5;
    }
}
int n, m;
void solve(C *a, C *b) {
    int lim = 1, L = 0;
    while(lim <= n + m) lim <<= 1, ++L;
    for(int i = 0; i < lim; i++) r[i] = (r[i >> 1] >> 1) | ((i & 1) << (L - 1));
    for(int i = n + 1; i < lim; i++) a[i] = C();
    for(int i = m + 1; i < lim; i++) b[i] = C();
    FFT(a, 1, lim); FFT(b, 1, lim);
    for(int i = 0; i < lim; i++) a[i] = a[i] * b[i];
    FFT(a, -1, lim);
}

int f[N], g[N];
void DC_FFT(int l, int r) {
    if(l >= r) return;
    int mid = (l + r) >> 1;
    DC_FFT(l, mid);
    for(int i = 0; i < r - l; i++) {
        a[i] = (i + l > mid ? 0 : C(f[i + l] % MOD, 0));
        b[i] = C(g[i + 1] % MOD, 0);
    }
    n = m = r - l - 1;
    solve(a, b);
    for(int i = mid + 1; i <= r; i++) f[i] = (f[i] + ll(a[i - l - 1].x)) % MOD;
    DC_FFT(mid + 1, r);
}

void run(int n) {
    for(int i = 1; i <= n; i++) scanf("%d", &g[i]);
    f[0] = 1;
    DC_FFT(0, n);
    cout << f[n] << '\n';
    memset(f, 0, sizeof(f));
}

int main() {
    int n;
    while(scanf("%d", &n) && n) run(n);
    return 0;
}

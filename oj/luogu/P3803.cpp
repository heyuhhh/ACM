/*
 * Author:  heyuhhh
 * Created Time:  2019/12/18 17:14:09
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
#define MP make_pair
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
#define Local
#ifdef Local
  #define dbg(args...) do { cout << #args << " -> "; err(args); } while (0)
  void err() { std::cout << '\n'; }
  template<typename T, typename...Args>
  void err(T a, Args...args) { std::cout << a << ' '; err(args...); }
#else
  #define dbg(...)
#endif
void pt() {std::cout << '\n'; }
template<typename T, typename...Args>
void pt(T a, Args...args) {std::cout << a << ' '; pt(args...); }
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//head
const int N = 4e6 + 5;
const double pi = acos(-1.0);
struct C{
    double x, y;
    C (double xx = 0, double yy = 0) {x = xx, y = yy;}
}a[N], b[N];
C operator + (C a, C b) {return C(a.x + b.x, a.y + b.y);}
C operator - (C a, C b) {return C(a.x - b.x, a.y - b.y);}
C operator * (C a, C b) {return C(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);}
int l, r[N];
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
}
int n, m;
void solve(C *a, C *b) {
    int lim = 1;
    while(lim <= n + m) lim <<= 1, l++;
    for(int i = 0; i < lim; i++) {
        r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
    }
    for(int i = n + 1; i < lim; i++) a[i] = C();
    for(int i = m + 1; i < lim; i++) b[i] = C();
    FFT(a, 1, lim); FFT(b, 1, lim);
    for(int i = 0; i < lim; i++) a[i] = a[i] * b[i];
    FFT(a, -1, lim);
    for(int i = 0; i < lim; i++) a[i].x = int(a[i].x / lim + 0.5);
}

void run(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i <= n; i++) {
        int x; scanf("%d", &x); 
        a[i] = C(x);   
    }
    for(int i = 0; i <= m; i++) {
        int x; scanf("%d", &x);
        b[i] = C(x);
    }
    solve(a, b);
    for(int i = 0; i <= n + m; i++) printf("%d ", (int)a[i].x);
}

int main() {
    run();
    return 0;
}

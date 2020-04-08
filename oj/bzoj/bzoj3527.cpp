/*
 * Author:  heyuhhh
 * Created Time:  2020/4/8 13:32:01
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
const int N = 4e5 + 5;
const double pi = acos(-1.0);
struct C{
    double x, y;
    C (double xx = 0, double yy = 0) {x = xx, y = yy;}
}a[N], b[N], c[N], d[N];
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
        for(int i = 0; i < n; i++) A[i].x = A[i].x / n;
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

double q[N], q2[N], ans[N];

void run() {
    int t; cin >> t;
    for(int i = 1; i <= t; i++) {
        scanf("%lf", &q[i]);
        q2[t - i + 1] = q[i];
    }
    for(int i = 1; i <= t; i++) a[i] = C(q[i]), c[i] = C(q2[i]);
    for(int i = 1; i <= t; i++) b[i] = d[i] = C(1.0 / i / i);
    a[0] = b[0] = c[0] = d[0] = C();
    n = m = t;
    solve(a, b), solve(c, d);
    for(int i = 1; i <= t; i++) ans[i] = a[i].x - c[t - i + 1].x;
    for(int i = 1; i <= t; i++) {
        printf("%.5f\n", ans[i]);   
    }
}

int main() {
    run();
    return 0;
}

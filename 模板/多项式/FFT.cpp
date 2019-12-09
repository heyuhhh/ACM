const double pi = acos(-1.0);
struct C{
    double x, y;
    C (double xx = 0, double yy = 0) {x = xx, y = yy;}
}a[N], b[N], c[N];
C operator + (C a, C b) {return C(a.x + b.x, a.y + b.y);}
C operator - (C a, C b) {return C(a.x - b.x, a.y - b.y);}
C operator * (C a, C b) {return C(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);}
int l, r[N];
int lim = 1;
void solve(C *A, int type) {
    for(int i = 0; i < lim; i++) if(i < r[i]) swap(A[i], A[r[i]]);
    for(int mid = 1; mid < lim; mid <<= 1) {
        C Wn(cos(pi / mid), type * sin(pi / mid)) ;
        for(int R = mid << 1, j = 0; j < lim; j += R) {
            C w(1, 0);
            for(int k = 0; k < mid; k++, w = w * Wn) {
                C x = A[j + k], y = w * A[j + mid + k];
                A[j + k] = x + y;
                A[j + mid + k] = x - y;
            }
        }
    }
}
void FFT(C *a, C *b) {
    while(lim <= n + m) lim <<= 1, l++;
    for(int i = 0; i < lim; i++) {
        r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
    }
    for(int i = n + 1; i < lim; i++) a[i] = C();
    for(int i = m + 1; i < lim; i++) b[i] = C();
    solve(a, 1); solve(b, 1);
    for(int i = 0; i <= lim; i++) c[i] = a[i] * b[i];
    solve(c, -1);
    for(int i = 0; i <= n + m; i++) c[i].x = (c[i].x / lim + 0.5);
}

#include <bits/stdc++.h>
using namespace std;
const int maxn = 35;
typedef long long LL;
typedef int Matrix[maxn][maxn];
int t, n, mod, cur, pre = 1, f[3][maxn << 1 | 1], deg[3];
LL m;
Matrix mat[3];
inline void mod_inc(int &x, int y) {
    (x += y) >= mod && (x -= mod);
}
inline int mod_inv(int x) {
    int y = mod, u = 1, v = 0;
    while(x) {
        int q = y / x;
        swap(x, y);
        x -= q * y;
        swap(u, v);
        u -= q * v;
    }
    assert(y == 1);
    return v < 0 ? v + mod : v;
}
inline int mat_half_det(Matrix &mat) {
    int odd = 1, even = 1;
    for(int i = 0; i < n; ++i) {
        int &det = i & 1 ? odd : even;
        for(int j = i; j < n; ++j) {
            if(!mat[j][i])
                continue;
            if(i == j)
                break;
            if(det)
                det = mod - det;
            for(int k = i; k < n; ++k)
                swap(mat[i][k], mat[j][k]);
        }
        if(!mat[i][i]) {
            det = 0;
            continue;
        }
        det = (LL)det * mat[i][i] % mod;
        for(int j = i, k = mod_inv(mat[i][i]); j < n; ++j)
            mat[i][j] = (LL)mat[i][j] * k % mod;
        for(int j = i + 1; j < n; ++j) {
            if(!mat[j][i])
                continue;
            int d = mod - mat[j][i];
            for(int k = i; k < n; ++k)
                mat[j][k] = (mat[j][k] + (LL)d * mat[i][k]) % mod;
        }
    }
    return even;
}
inline void poly_mod() {
    int *G = f[2];
    for(int i = deg[cur] - n; i >= 0; --i) {
        int *F = f[cur] + i;
        if(!F[n])
            continue;
        int d = mod - F[n];
        for(int j = 0; j <= n; ++j)
            F[j] = (F[j] + (LL)d * G[j]) % mod;
    }
    for(deg[cur] > n && (deg[cur] = n); deg[cur] && !f[cur][deg[cur]]; --deg[cur]);
}
inline void mat_next() {
    swap(cur, pre);
    Matrix &F = mat[cur], &G = mat[pre];
    for(int i = 0; i < n; ++i)
        for(int j = 1; j < n; ++j) {
            mod_inc(F[i][j], G[i][j - 1]);
            mod_inc(F[i][j - 1], G[i][j]);
        }
}
int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%lld%d", &n, &m, &mod);
        assert(mod > 1);
        if((n & 1) && (m & 1)) {
            puts("0");
            continue;
        }
        if(n > m) {
            int t = m;
            m = n;
            n = t;
        }
        if(n == 1) {
            puts("1");
            continue;
        }
        f[cur][0] = 1;
        for(int i = 1; i <= n; ++i) {
            swap(cur, pre);
            f[cur][i] = f[pre][i - 1];
            for(int j = i - 1; j > 0; --j) {
                f[cur][j] = f[pre][j - 1];
                mod_inc(f[cur][j], mod - f[pre][j]);
                mod_inc(f[cur][j], mod - f[cur][j - 1]);
            }
            assert(f[pre][0]);
            f[cur][0] = mod - f[pre][0];
        }
        memcpy(f[2], f[cur], (n + 1) * sizeof(int));
        assert(f[2][n] == 1);
        deg[cur] = 0;
        f[cur][0] = 1;
        int mx = 0;
        for( ; (1LL << mx) <= (m >> 1); ++mx);
        for(int i = mx - 1; i >= 0; --i) {
            swap(cur, pre);
            deg[cur] = deg[pre] << 1;
            memset(f[cur], 0, (deg[cur] + 1) * sizeof(int));
            for(int j = 0; j <= deg[pre]; ++j)
                for(int k = 0; k <= deg[pre]; ++k)
                    f[cur][j + k] = (f[cur][j + k] + (LL)f[pre][j] * f[pre][k]) % mod;
            poly_mod();
            if((m >> (i + 1)) & 1) {
                ++deg[cur];
                for(int i = deg[cur]; i > 0; --i)
                    f[cur][i] = f[cur][i - 1];
                f[cur][0] = 0;
                poly_mod();
            }
        }
        deg[2] = deg[cur];
        memcpy(f[2], f[cur], (deg[2] + 1) * sizeof(int));
        for(int i = 0; i < n; ++i) {
            memset(mat[0][i], 0, n * sizeof(int));
            memset(mat[1][i], 0, n * sizeof(int));
            memset(mat[2][i], 0, n * sizeof(int));
        }
        for(int i = 0; i <= deg[2]; ++i) {
            if(i) {
                mat_next();
                mat_next();
            } else {
                for(int j = 0; j < n; ++j)
                    mat[cur][j][j] = 1;
                if(m & 1)
                    mat_next();
            }
            if(f[2][i]) {
                for(int j = 0; j < n; ++j)
                    for(int k = 0; k < n; ++k)
                        if(mat[cur][j][k])
                            mat[2][j][k] = (mat[2][j][k] + (LL)f[2][i] * mat[cur][j][k]) % mod;
            }
        }
        int ans = mat_half_det(mat[2]);
        if((n & 3) == 2 && (m & 1) && ans)
            ans = mod - ans;
        printf("%d\n", ans);
    }
    return 0;
}

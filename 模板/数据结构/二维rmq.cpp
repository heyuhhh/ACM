struct RMQ {
    int f[N][N][9][9], g[N][N][9][9];
    int mm[N];
    void init(int n, int m, int a[][N]) {
        mm[0] = -1;
        for (int i = 1; i < N; ++i) {
            mm[i] = ((i & (i - 1)) == 0) ? mm[i - 1] + 1 : mm[i - 1];
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                f[i][j][0][0] = a[i][j];
                g[i][j][0][0] = a[i][j];
            }
        }
        for (int ii = 0; ii <= mm[n]; ++ii) {
            for (int jj = 0; jj <= mm[m]; ++jj) {
                if (ii + jj) {
                    for (int i = 1; i + (1 << ii) - 1 <= n; ++i) {
                        for (int j = 1; j + (1 << jj) - 1 <= m; ++j) {
                            if (ii) {
                                f[i][j][ii][jj] = max(f[i][j][ii - 1][jj], f[i + (1 << (ii - 1))][j][ii - 1][jj]);
                                g[i][j][ii][jj] = min(g[i][j][ii - 1][jj], g[i + (1 << (ii - 1))][j][ii - 1][jj]);
                            } else {
                                f[i][j][ii][jj] = max(f[i][j][ii][jj - 1], f[i][j + (1 << (jj - 1))][ii][jj - 1]);
                                g[i][j][ii][jj] = min(g[i][j][ii][jj - 1], g[i][j + (1 << (jj - 1))][ii][jj - 1]);
                            }
                        }
                    }
                }
            }
        }
    } 
    void Max(int &x, short y) {
        if (x < y) x = y;
    }
    void Min(int &x, short y) {
        if (x > y) x = y;
    }
    pII query(int x1, int y1, int x2, int y2) {
        int k1 = mm[x2 - x1 + 1];
        int k2 = mm[y2 - y1 + 1];
        x2 = x2 - (1 << k1) + 1;
        y2 = y2 - (1 << k2) + 1;
        pII res = pII(-INF, INF); 
        Max(res.fi, f[x1][y1][k1][k2]);
        Max(res.fi, f[x1][y2][k1][k2]);
        Max(res.fi, f[x2][y1][k1][k2]);
        Max(res.fi, f[x2][y2][k1][k2]);
        Min(res.se, g[x1][y1][k1][k2]);
        Min(res.se, g[x1][y2][k1][k2]);
        Min(res.se, g[x2][y1][k1][k2]);
        Min(res.se, g[x2][y2][k1][k2]);
        return res;
    }
}rmq;

namespace R {
    int n;
    int w[N][N], kx[N], ky[N], py[N], vy[N], slk[N], pre[N];
    ll KM() {
        fill(kx, kx + n + 1, 0);
        fill(ky, ky + n + 1, 0);
        fill(py, py + n + 1, 0);
        for(int i = 1; i <= n; i++) 
            for(int j = 1; j <= n; j++)
                kx[i] = max(kx[i], w[i][j]);
                
        for(int i = 1; i <= n; i++) {
            fill(vy, vy + n + 1, 0);
            fill(slk, slk + n + 1, INF);
            fill(pre, pre + n + 1, 0);
            int k = 0, p = -1;
            for(py[k = 0] = i; py[k]; k = p) {
                int d = INF;
                vy[k] = 1;
                int x = py[k];
                for(int j = 1; j <= n; j++)
                    if (!vy[j]) {
                        int t = kx[x] + ky[j] - w[x][j];
                        if (t < slk[j]) { slk[j] = t; pre[j] = k; }
                        if (slk[j] < d) { d = slk[j]; p = j; }
                    }
                for(int j = 0; j <= n; j++)
                    if (vy[j]) { kx[py[j]] -= d; ky[j] += d; }
                    else slk[j] -= d;
            }
            for (; k; k = pre[k]) py[k] = py[pre[k]];
        }
        ll ans = 0;
        for(int i = 1; i <= n; i++) ans += kx[i] + ky[i];
        return ans;
    }
}

int cx, cy, ct;
int vx[N], vy[N], w[N][N];
int lnk[N], pre[N], slk[N];
bool vis[N];

void bfs(int x, int y = 0) {
    lnk[0] = x, memset(pre, 0, (ct + 1) * sizeof(int));
    memset(slk, 63, (ct + 1) * sizeof(int));
    memset(vis, false, (ct + 1) * sizeof(bool));
    for(int ny, mi; lnk[y]; y = ny) {
        x = lnk[y], mi = INF, vis[y] = true;
        for(int i = 1; i <= ct; i++) {
            if(vis[i]) continue;
            if(slk[i] > vx[x] + vy[i] - w[x][i])
                slk[i] = vx[x] + vy[i] - w[x][i], pre[i] = y;
            if(slk[i] < mi) mi = slk[i], ny = i;
        }
        for(int i = 0; i <= ct; i++)
            vis[i] ? vx[lnk[i]] -= mi, vy[i] += mi : slk[i] -= mi;
    }
    for(; y; y = pre[y]) lnk[y] = lnk[pre[y]];
}

ll km() {
    for(int i = 1; i <= ct; i++) bfs(i);
    ll ans = 0;
    for(int i = 1; i <= ct; i++) ans += vx[i] + vy[i];
    return ans;
}

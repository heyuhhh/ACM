struct SA{                                       //sa:1...n  Rank:0...n-1
    int t1[N], t2[N], sa[N], c[N], height[N], Rank[N];
    int f[N][20], lg[N];
    int n;                                          //length
    void da(char *s, int m){
        s[++n] = 0;
        int* x = t1, *y = t2;
        for(int i = 0; i < m; i++) c[i] = 0;
        for(int i = 0; i < n; i++) c[x[i] = s[i]]++;
        for(int i = 1; i < m; i++) c[i] += c[i - 1] ;
        for(int i = n - 1; i >= 0; i--) sa[--c[x[i]]] = i;
        for(int k = 1; k <= n; k <<= 1) {
            int p = 0 ;
            for(int i = n - k; i < n; i++) y[p++] = i ;
            for(int i = 0; i < n; i++) if(sa[i] >= k) y[p++] =sa[i] - k;
            for(int i = 0; i < m; i++) c[i] = 0;
            for(int i = 0; i < n; i++) c[x[y[i]]]++;
            for(int i = 1; i < m; i++) c[i] += c[i - 1];
            for(int i = n - 1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i] ;
            swap(x , y); p = 1; x[sa[0]] = 0;
            for(int i = 1; i < n; i++)
                x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i-1] + k] == y[sa[i] + k] ? p - 1 : p++;
            if(p >= n) break ;
            m = p;
        }
        n--;
        int k = 0;
        for(int i = 0; i <= n; i++) Rank[sa[i]] = i;
        for(int i = 0; i < n; i++) {
            if(k) k--;
            int j = sa[Rank[i] - 1];
            while(s[i + k] == s[j + k]) k++;
            height[Rank[i]] = k;
        }
    }
    ll count() {
        ll ans = 0;
        for(int i = 1; i <= n; i++) ans += n - sa[i] - height[i];
        return ans;
    }
    void init() {
        for(int i = 2; i < N; i++) lg[i] = lg[i >> 1] + 1;
        for(int i = 2; i <= n; i++) f[i][0] = height[i];
        for(int j = 1; j < 20; j++)
            for(int i = 2; i + (1 << j) - 1 <= n; i++)
                f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]) ;
    }
    int get_lcp(int l, int r) {
        if(Rank[l] > Rank[r]) swap(l, r);
        l = Rank[l] + 1, r = Rank[r];
        int k = lg[r - l + 1];
        return min(f[l][k], f[r - (1 << k) + 1][k]);
    }
}

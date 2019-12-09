struct node{
    int ch[26];
    int len, fa;
    node(){memset(ch, 0, sizeof(ch)), len = 0;}
}dian[N];
int last = 1, tot = 1;
ll ans[N], f[N];
void add(int c) {
    int p = last;
    int np = last = ++tot;
    dian[np].len = dian[p].len + 1;
    f[np] = 1;
    for(; p && !dian[p].ch[c]; p = dian[p].fa) dian[p].ch[c] = np;
    if(!p) dian[np].fa = 1;
    else {
        int q = dian[p].ch[c];
        if(dian[q].len == dian[p].len + 1) dian[np].fa = q;
        else {
            int nq = ++tot; dian[nq] = dian[q];
            dian[nq].len = dian[p].len + 1;
            dian[q].fa = dian[np].fa = nq;
            for(; p && dian[p].ch[c] == q; p = dian[p].fa) dian[p].ch[c] = nq;
        }
    }
}
int q[N], in[N]; //*2 
void topsort() {
    int l = 1, r = 0;
    for(int i = 1; i <= tot; i++) in[dian[i].fa]++;
    for(int i = 1; i <= tot; i++) if(!in[i]) q[++r] = i;
    while(l <= r) {
        int x = q[l++];
        f[dian[x].fa] += f[x];
        if(--in[dian[x].fa] == 0) q[++r] = dian[x].fa;
    }
} 

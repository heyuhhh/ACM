/*
	一般用来求解本质不同的回文串相关问题，每个结点到根都代表一个回文后缀。
	
	与AC自动机有点类似。
*/
namespace PAM{
    int ch[N][26], fail[N], len[N], st[N], cnt[N];
    int sz, n, last;
    int New(int l, int f) {
        memset(ch[++sz], 0, sizeof(ch[sz]));
        len[sz] = l, fail[sz] = f;
        return sz;
    }
    void init() {
        sz = -1;
        New(0, 1); last = New(-1, 0);
        st[n = 0] = -1;
        memset(cnt, 0, sizeof(cnt));
    }
    int getf(int x) {
        while(st[n - len[x] - 1] != st[n]) x = fail[x];
        return x;
    }
    bool Insert(int c) { //int
        st[++n] = c;
        int x = getf(last);
        bool F = 0;
        if(!ch[x][c]) {
            F = 1;
            int f = getf(fail[x]);
            ch[x][c] = New(len[x] + 2, ch[f][c]);
        }
        last = ch[x][c];
        cnt[last]++;
        return F;
    }
    void count() {
        for(int i = sz; i >= 1; i--) cnt[fail[i]] += cnt[i];
    }
};

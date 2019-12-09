struct B{
    const int mod = 524287; // (1 << 19) - 1;
    int tot;
    int h[524288], next[524288], L[524288], v[524288];
    int Find(ll x) {
        int k = h[x & mod];
        while(k != 0) {
            if(L[k] == x) return v[k];
            else k = next[k];
        }
        return -1;
    }
    void Add(int e, int i) {
        tot++;
        next[tot] = h[e & mod];
        L[tot] = e; v[tot] = i;
        h[e & mod] = tot;
    }
    void init(int a, int n) {
        memset(h, 0, sizeof(h)); memset(L, 0, sizeof(L));tot = 0;
        memset(next, 0, sizeof(next)); memset(v, 0, sizeof(v));
        ll t, e = 1;
        t = (int)sqrt(n) + 1;
        for(int i = 0; i < t; i++) {
            if(Find(e) == -1) Add(e, i);
            e = e * a % n;
        }
    }
    ll BSGS(int a, int b, int n, ll v, ll t) { // a ^ x = b (mod n)
        for(int i = 0; i < t; i++) {
            if(Find(b) != -1) return i * t + Find(b);
            b = b * v % n;
        }
        return -1;
    }
}S;

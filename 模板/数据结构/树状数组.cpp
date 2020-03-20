struct BIT {
    int c[N];
    int lowbit(int x) {return x & (-x);}
    void add(int x, int v = 1) {
        for(; x < N; x += lowbit(x)) c[x] += v;
    }
    int query(int x) {
        int res = 0;
        for(; x; x -= lowbit(x)) res += c[x];
        return res;   
    }
    int query(int l, int r) {
        return query(r) - query(l - 1);   
    }
}bit;

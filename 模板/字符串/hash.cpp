typedef unsigned long long ull;
template <unsigned mod, unsigned base>
struct rolling_hash {
    unsigned int pg[N], val[N]; // val:1,2...n
    rolling_hash() {
        pg[0] = 1;
        for(int i = 1; i < N; i++) pg[i] = 1ull * pg[i - 1] * base % mod;
        val[0] = 0;
    }
    void build(const char *str) {
        for(int i = 0; str[i]; i++) {
            val[i + 1] = (str[i] + 1ull * val[i] * base) % mod;
        }
    }
    unsigned int operator() (int l, int r) {
        ++r; // 
        return (val[r] - 1ull * val[l] * pg[r - l] % mod + mod) % mod;
    }
};
struct dm_hasher {
    //str:0,1...len-1
    rolling_hash<997137961, 753> h1;
    rolling_hash<1003911991, 467> h2;
    void build(const char *str) {
        h1.build(str); h2.build(str);
    }
    ull operator() (int l, int r) {
        return ull(h1(l, r)) << 32 | h2(l, r);
    }
}hasher;


// 双模数hash，同时用链表维护hash值，支持插入hash值以及询问hash值对应的值
struct Hash {
    static const int MO = 19260817;
    int ka[N], kb[N], v[N], head[MO], next[N];
    int sta[N], top, sz;
  
    int getHash(int A, int B) {
        return (1ll * A * 2333 + B) % MO;
    }
    void init() {
        while (top) {
            head[sta[top--]] = 0;
        }
        sz = 0;
    }
    void add(int x, int y, int c) {
        int ha = getHash(x, y);
        for (int i = head[ha]; i; i = next[i]) {
            if (ka[i] == x && kb[i] == y) {
                v[i] += c;
                return;
            }
        }
        ka[++sz] = x, kb[sz] = y, v[sz] = c, next[sz] = head[ha], head[ha] = sz;
        sta[++top] = ha;
    }
    int query(int x, int y) {
        int ha = getHash(x, y);
        for (int i = head[ha]; i; i = next[i]) {
            if (ka[i] == x && kb[i] == y) {
                return v[i];
            }
        }
        return 0;
    }
}A, B;
// 子集卷积，计算 h(S)=\sum_{s\in S,t=S-s}f(s)*g(t)
// 通过集合并卷积(FMT)记录二进制中1的个数得到，时间复杂度为O(n^2 * 2^n)
const int Len = 1 << 21, Base = 21;

int add(int x, int y) {return x + y >= MOD ? x + y - MOD : x + y;}
int dec(int x, int y) {return x - y < 0 ? x - y + MOD : x - y;}
int mul(int x, int y) {return 1ll * x * y % MOD;}

inline void fmt_or(vector<int>& A, int dmt = 1, int base = Base) {
    int len = 1 << base;
    for (int i = 1; i < len; i <<= 1)
        for (int j = 0, t = i << 1; j < len; j += t)
            for (int k = j, K = j + i; k < K; ++k) 
                A[k + i] = (dmt > 0 ? add(A[k + i], A[k]) : dec(A[k + i], A[k]));
}

// 计算二进制中1的个数
vector<int> pc;
void get_top(int sz) {
    pc.resize(sz, 0);
    for (int i = 1; i < sz; ++i) pc[i] = pc[i >> 1] + (i & 1);
}

vector<int> subset_conv(const vector<int>& A, const vector<int>& B, int base) {
    int len = 1 << base;
    vector<int> H(len);
    vector<vector<int> > siga(base + 1, vector<int>(len, 0)), sigb = siga, sigh = siga;
    for (int S = 0; S < len; ++S) siga[pc[S]][S] = A[S], sigb[pc[S]][S] = B[S];
    for (int i = 0; i <= base; ++i) {
        fmt_or(siga[i], 1, base);
        fmt_or(sigb[i], 1, base);
        for (int S = 0; S < len; ++S)
            for (int j = 0; j <= i; ++j) sigh[i][S] = add(sigh[i][S], mul(siga[j][S], sigb[i - j][S]));
        fmt_or(sigh[i], -1, base);
    }
    for (int S = 0; S < len; ++S) H[S] = sigh[pc[S]][S];
    return H;
}
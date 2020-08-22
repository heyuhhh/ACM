// Author : heyuhhh
// Created Time : 2020/08/12 14:46:46
#include<bits/stdc++.h>
#define MP make_pair
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//head
const int N = 1e5 + 5, MOD = 998244353;

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

vector<int> gao(const vector<int>& a) {
    get_top(Len);
    vector<int> res(Len, 0);
    res[0] = 1;
    for (int n = 0; n < Base; n++) {
        vector<int> A(res.begin(), res.begin() + (1 << n));
        vector<int> B(a.begin() + (1 << n), a.begin() + (1 << (n + 1)));
        A = subset_conv(A, B, n);
        for (int i = (1 << n); i < (1 << (n + 1)); i++) {
            res[i] = A[i - (1 << n)];
        }
    }
    return res;
}

void run() {
    int n;
    cin >> n;
    vector<int> b(Len);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        b[y] = add(b[y], x);
    }
    vector<int> ans = gao(b);
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        cout << ans[x] << '\n';
    }
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
//����ǰ2*k�� 
#define rep(i,a,n) for (int i=a;i<n;i++)
#define SZ(x) ((int)(x).size())

typedef vector<int> VI;
typedef long long ll;

ll powMOD(ll a, ll b) {
    ll ans = 1;
    for (; b; b >>= 1, a = a * a%MOD)if (b & 1)ans = ans * a%MOD;
    return ans;
}
namespace linear_seq {
    const int N = 10010;
    ll res[N], base[N], _c[N], _md[N];

    vector<int> Md;
    void mul(ll *a, ll *b, int k) {
        rep(i, 0, k + k) _c[i] = 0;
        rep(i, 0, k) if (a[i]) rep(j, 0, k) _c[i + j] = (_c[i + j] + a[i] * b[j]) % MOD;
        for (int i = k + k - 1; i >= k; i--) if (_c[i])
            rep(j, 0, SZ(Md)) _c[i - k + Md[j]] = (_c[i - k + Md[j]] - _c[i] * _md[Md[j]]) % MOD;
        rep(i, 0, k) a[i] = _c[i];
    }
    int solve(ll n, VI a, VI b) { // a ϵ�� b ��ֵ b[n+1]=a[0]*b[n]+...
        ll ans = 0, pnt = 0;
        int k = SZ(a);
        assert(SZ(a) == SZ(b));
        rep(i, 0, k) _md[k - 1 - i] = -a[i]; _md[k] = 1;
        Md.clear();
        rep(i, 0, k) if (_md[i] != 0) Md.push_back(i);
        rep(i, 0, k) res[i] = base[i] = 0;
        res[0] = 1;
        while ((1ll << pnt) <= n) pnt++;
        for (int p = pnt; p >= 0; p--) {
            mul(res, res, k);
            if ((n >> p) & 1) {
                for (int i = k - 1; i >= 0; i--) res[i + 1] = res[i]; res[0] = 0;
                rep(j, 0, SZ(Md)) res[Md[j]] = (res[Md[j]] - res[k] * _md[Md[j]]) % MOD;
            }
        }
        rep(i, 0, k) ans = (ans + res[i] * b[i]) % MOD;
        if (ans < 0) ans += MOD;
        return ans;
    }
    VI BM(VI s) {
        VI C(1, 1), B(1, 1);
        int L = 0, m = 1, b = 1;
        rep(n, 0, SZ(s)) {
            ll d = 0;
            rep(i, 0, L + 1) d = (d + (ll)C[i] * s[n - i]) % MOD;
            if (d == 0) ++m;
            else if (2 * L <= n) {
                VI T = C;
                ll c = MOD - d * powMOD(b, MOD - 2) % MOD;
                while (SZ(C) < SZ(B) + m) C.pb(0);
                rep(i, 0, SZ(B)) C[i + m] = (C[i + m] + c * B[i]) % MOD;
                L = n + 1 - L; B = T; b = d; m = 1;
            }
            else {
                ll c = MOD - d * powMOD(b, MOD - 2) % MOD;
                while (SZ(C) < SZ(B) + m) C.pb(0);
                rep(i, 0, SZ(B)) C[i + m] = (C[i + m] + c * B[i]) % MOD;
                ++m;
            }
        }
        return C;
    }
    int gao(VI a, ll n) {
        VI c = BM(a);
        c.erase(c.begin());
        rep(i, 0, SZ(c)) c[i] = (MOD - c[i]) % MOD;
        return solve(n, c, VI(a.begin(), a.begin() + SZ(c)));
    }
};

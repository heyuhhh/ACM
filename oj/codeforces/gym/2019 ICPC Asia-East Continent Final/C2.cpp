#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 100005, M = 61, MOD = 998244353;

int qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

inline int add(int x, int y) {
    return x + y >= MOD ? x + y - MOD : x + y;
}
inline int mul(int x, int y) {
    return 1ll * x * y % MOD;
}

int n, k;
int f[N], g[N];
int F[M][N], tmp[M], tot;

vector<int> d[N];

void run() {
    cin >> n >> k;
    int invk = qpow(k, MOD - 2);
    for (int i = 1; i <= n; i++) {
        cin >> g[i];
    }
    for (int i = 2; i <= n; i++) {
        for (int j = i + i; j <= n; j += i) {
            d[j].emplace_back(i);
        }
    }    
    int t = k;
    while (t) {
        tmp[++tot] = t;
        if (t & 1) {
            --t;
        } else {
            t >>= 1;
        }
    }
    f[1] = 1;
    for (int i = 1; i <= tot; i++) {
        F[i][1] = 1;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = tot - 1; j >= 1; j--) {
            for (auto& ds : d[i]) {
                if (tmp[j] & 1) {
                    F[j][i] = add(F[j][i], mul(F[j + 1][ds], f[i / ds]));
                } else {
                    F[j][i] = add(F[j][i], mul(F[j + 1][ds], F[j + 1][i / ds]));
                }
            }
            if (tmp[j] & 1) {
                F[j][i] = add(F[j][i], mul(F[j + 1][i], f[1]));
            } else {
                F[j][i] = add(F[j][i], mul(2, mul(F[j + 1][i], F[j + 1][1])));
            }
        }
        int res = (g[i] - F[1][i] + MOD) % MOD;
        f[i] = mul(res, invk);
        F[tot][i] = f[i];
        for (int j = tot - 1; j >= 1; j--) {
            F[j][i] = add(F[j][i], mul(tmp[j], f[i]));
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << f[i] << " \n"[i == n];
    }
}

int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    run();
    return 0;
}
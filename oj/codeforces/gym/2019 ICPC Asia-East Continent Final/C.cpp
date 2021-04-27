#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 100005, MOD = 998244353;

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

int primes[N], minp[N], tot;
int inv[N];

void init() {
    inv[0] = inv[1] = 1;
    for (int i = 2; i < N; i++) {
        inv[i] = 1ll * (MOD - MOD / i) * inv[MOD % i] % MOD;
    }
    for (int i = 2; i < N; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes[++tot] = i;
            for (int j = 1; j <= tot && primes[j] * i < N; j++) {
                minp[i * primes[j]] = i;
                if (i % primes[j] == 0) {
                    break;
                }
            }
        }
    }
}

int n, k;
int f[N], g[N];

vector<int> d[N];

void run() {
    cin >> n >> k;
    int invk = qpow(k, MOD - 2);
    auto C = [&] (int p) {
        int res = 1;
        for (int i = k - 1; i < p + k - 1; i++) {
            res = mul(res, i);
        }
        for (int i = 1; i <= p; i++) {
            res = mul(res, inv[i]);
        }
        return res;
    };
    for (int i = 1; i <= n; i++) {
        cin >> g[i];
    }
    f[1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            d[j].emplace_back(i);
        }
    }
    for (int i = 2; i <= n; i++) {
        int A = 0;
        for (auto& ds : d[i]) {
            int r = i / ds;
            A = add(A, mul(k, mul(g[r], f[ds])));
        }
        int now = (g[i] - A + MOD) % MOD;
        f[i] = now;
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
    init();
    run();
    return 0;
}
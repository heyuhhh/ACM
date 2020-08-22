// Author : heyuhhh
// Created Time : 2020/08/19 22:52:22
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
const int N = 1e7 + 5, MOD = 1e9 + 7;

int f[N], g[N];
bool vis[N];
int primes[N], tot;

void init() {
    int inv2 = (MOD + 1) / 2;
    f[1] = 1; g[1] = 1;
    for (int i = 2; i < N; i++) {
        if (!vis[i]) {
            primes[++tot] = i;
            f[i] = 2;
            g[i] = MOD - inv2;
        }
        for (int j = 1; j <= tot && primes[j] * i < N; j++) {
            vis[i * primes[j]] = 1;
            if (i % primes[j]) {
                f[i * primes[j]] = 1ll * f[i] * 2 % MOD;
                g[i * primes[j]] = 1ll * g[i] * (MOD - inv2) % MOD;
                continue;
            }
            f[i * primes[j]] = f[i];
            break;
        }
    }
}

struct inf {
    int id, fir, sec;
    ll val;
};
int ans[N];

void run() {
    int q;
    cin >> q;
    vector<inf> v;
    for (int _ = 1; _ <= q; _++) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; 1ll * i * i <= n; i++) if (n % i == 0) {
            v.push_back(inf{_, i, m / i, 1ll * f[n] * g[i] % MOD});
            if (n / i != i) {
                v.push_back(inf{_, n / i, m / (n / i), 1ll * f[n] * g[n / i] % MOD});
            }
        }
    }
    sort(all(v), [&](inf A, inf B) {
        if (A.fir != B.fir) return A.fir < B.fir;
        return A.sec < B.sec;
    });
    
    int last = -1, i = 1, res = 0;
    for (auto& it : v) {
        if (it.fir != last) {
            last = it.fir;
            i = 1;
            res = 0;
        }
        for (; i <= it.sec; i++) {
            res = (res + f[i * it.fir]) % MOD;
        }
        ans[it.id] = (ans[it.id] + 1ll * it.val * res % MOD) % MOD;
    }

    for (int i = 1; i <= q; i++) {
        cout << ans[i] << '\n';
    }
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    init();
    run();
    return 0;
}
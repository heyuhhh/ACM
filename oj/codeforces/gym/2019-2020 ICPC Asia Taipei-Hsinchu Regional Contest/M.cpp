// Author : heyuhhh
// Created Time : 2020/10/01 19:47:18
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
int getInv(ll x, int P);
int qpow(ll a, ll b, int MOD) {
    ll res = 1;
    a %= MOD;
    if (b < 0) {
        return getInv(qpow(a, -b, MOD), MOD);
    }
    while(b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
int getInv(ll x, int P) {
    return qpow(x, P - 2, P);
}
vector<int> init(int p, int P) {
    vector<int> prod(P + 1);
    prod[0] = 1;
    for (int i = 1; i <= P; i++) {
        prod[i] = prod[i - 1];
        if (i % p) {
            prod[i] = 1ll * prod[i - 1] * i % P;
        }
    }
    return prod;
}
int calcVal(ll n, int p, int P, const vector<int>& prod) {
    if (n == 0) return 1;
    return 1ll * calcVal(n / p, p, P, prod) * prod[n % P] % P * qpow(prod[P], n / P, P) % P;
}
struct node {
    int p, cnt, val;
};
struct CRT{
    void exgcd(ll a, ll b, ll &g, ll &x, ll &y) {
        if(b == 0) {
            x = 1, y = 0, g = a;
            return ;
        }
        exgcd(b, a % b, g, x, y);
        int t = x;
        x = y;
        y = t - (a / b) * y;
    }
    ll china(vector<int>& m, vector<int>& a, int n) {
        ll M, Mi, d, X, Y, ans;
        M = 1; ans = 0;
        for(int i = 0; i < n; i++) M *= m[i];
        for(int i = 0; i < n; i++) {
            Mi = M / m[i];
            exgcd(Mi, m[i], d, X, Y);
            ans = (ans + Mi * X * a[i]) % M;
        }
        if(ans < 0) ans += M;
        return ans;
    }
}crt; 
void run() {
    ll n, m;
    int d;
    cin >> n >> m >> d;
    vector<node> primes;
    int x = d;
    for (int i = 2; i * i <= x; i++) if (x % i == 0) {
        primes.emplace_back(node{i, 0, 1});
        while (x % i == 0) {
            x /= i;
            ++primes.back().cnt;
            primes.back().val *= i;
        }
    }
    if (x > 1) {
        primes.emplace_back(node{x, 1, x});
    }
    vector<ll> nm_k;
    int s = sz(primes);
    ll K = 1e18;
    for (int i = 0; i < s; i++) {
        int p = primes[i].p;
        ll res = 0;
        for (ll t = n; t; t /= p) res += t / p;
        for (ll t = m; t; t /= p) res -= t / p;
        for (ll t = n - m; t; t /= p) res -= t / p;
        nm_k.emplace_back(res);
        K = min(K, res / primes[i].cnt);
    }

    // Solve C(n, m) / D ^ K (mod D)
    // D = D_1 * D_2 * ... * D_s, D_i = p_i ^ a_i
    // Solve C(n, m) / D ^ K (mod D_i)
    // => (C(n, m) div p_i) * p_i ^ k_i / D ^ k (mod D_i)
    // => (C(n, m) div p_i) * p_i ^ {k_i - K * a_i} / (D / D_i) ^ k (mod D_i)
    // How to calculate (C(n, m) div p_i)?
    // just like ex-lucas, consider to calculate the answer of n! by recursion.
    // The difference of it and ex-lucas is that, when in recursion, we don't need to multiply p ^ t.
    // At the end, we use ex-crt to combine the answers.
    vector<int> M, A;
    for (int i = 0; i < s; i++) {
        M.emplace_back(primes[i].val);
        node cur = primes[i];
        int MOD = cur.val;
        vector<int> tmp = init(cur.p, MOD);
        int res = 1ll * calcVal(n, cur.p, MOD, tmp) 
                    * getInv(calcVal(m, cur.p, MOD, tmp), MOD) % MOD
                    * getInv(calcVal(n - m, cur.p, MOD, tmp), MOD) % MOD
                    * qpow(cur.p, nm_k[i] - K * cur.cnt, MOD) % MOD
                    * getInv(qpow(d / MOD, K, MOD), MOD) % MOD;
        A.emplace_back(res);
    }
    int ans = crt.china(M, A, s);
    cout << ans << '\n';
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
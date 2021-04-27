#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 200000 + 5;

int qpow(ll a, ll b, int MOD) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int n, p;
int a[N];

void run() {
    cin >> n >> p;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    map<int, int> mp;
    for (int i = 2; i <= n; i++) {
        int q = 1ll * a[i] * qpow(a[i - 1], p - 2, p) % p;
        ++mp[q];
    }
    for (int i = 3; i <= n; i++) {
        int q = 1ll * a[i] * qpow(a[i - 2], p - 2, p) % p;
        ++mp[q];
    }
    int nd = min(9, sz(mp));
    vector<pii> V;
    for (auto& it : mp) {
        V.emplace_back(it.se, it.fi);
    }
    sort(all(V));
    reverse(all(V));
    int ans = 0;
    for (int t = 0; t < nd; t++) {
        int q = V[t].se;
        vector<int> f(n + 1, 1);
        map<int, int> last;
        vector<int> nxt(n + 1);
        for (int i = n; i >= 1; i--) {
            int to = 1ll * a[i] * q % p;
            if (last.find(to) != last.end()) {
                nxt[i] = last[to];
            }
            last[a[i]] = i;
        }
        for (int i = 1; i <= n; i++) if (nxt[i]) {
            f[nxt[i]] = max(f[nxt[i]], f[i] + 1);
        }
        ans = max(ans, *max_element(all(f)));
    }
    if (ans * 2 < n) ans = -1;
    cout << ans << '\n';
}

int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(0), cin.tie(0);
    int T; cin >> T; while (T--)
    run();
    return 0;
}
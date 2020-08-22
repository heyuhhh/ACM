// Author : heyuhhh
// Created Time : 2020/08/08 14:15:43
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
int qpow(ll a, ll b) {
    ll res = 1;
    while(b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void run() {
    int a, b, c, d, x, y;
    cin >> a >> b >> c >> d >> x >> y;
    vector<pii> v;
    vector<pii> px, py;
    for (register int i = 2; 1ll * i * i <= x; ++i) {
        if (x % i == 0) {
            int cnt = 0;
            while (x % i == 0) {
                ++cnt;
                x /= i;
            }
            v.emplace_back(MP(i, cnt));
        }
    }
    if (x > 1) {
        v.emplace_back(MP(x, 1));
    }
    for (register int i = 2; 1ll * i * i <= y; ++i) {
        if (y % i == 0) {
            int flag = -1;
            for (register int j = 0; j < sz(v); ++j) {
                if (v[j].fi == i) {
                    flag = j;
                    break;
                }
            }
            int cnt = 0;
            while (y % i == 0) {
                ++cnt;
                y /= i;
            }
            if (flag >= 0) {
                px.emplace_back(MP(i, v[flag].se));
                py.emplace_back(MP(i, cnt));
            }
        }
    }
    if (y > 1) {
        int flag = -1;
        for (register int j = 0; j < sz(v); ++j) {
            if (v[j].fi == y) {
                flag = j;
                break;
            }
        }
        if (flag >= 0) {
            px.emplace_back(MP(y, v[flag].se));
            py.emplace_back(MP(y, 1));
        }
    }
    int ans = 1;
    for (register int k = 0; k < sz(px); ++k) {
        int p = px[k].fi;
        int c1 = px[k].se, c2 = py[k].se;
        assert(c1 <= 40 && c2 <= 40);

        ll res = 0;
        for (register int i = a; i <= b; ++i) {
            int least = max(c, ((i * c1 + c2 - 1) / c2));
            if (least > d) break;
            res += 1ll * i * c1 % (MOD - 1) * (d - least + 1) % (MOD - 1);
            res %= (MOD - 1);
        }
        
        for (register int i = c; i <= d; ++i) {
            int least = max(a, (i * c2) / c1 + 1);
            if (least > b) break;
            res += 1ll * i * c2 % (MOD - 1) * (b - least + 1) % (MOD - 1);
            res %= (MOD - 1);
        }
        ans = 1ll * ans * qpow(p, res) % MOD;
    }
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
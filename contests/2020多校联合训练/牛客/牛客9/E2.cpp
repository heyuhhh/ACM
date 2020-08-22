#include<bits/stdc++.h>
#define MP make_pair
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//head
const int MOD = 998244353;
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
    int n = x, m = y;
    vector<pii> v;
    vector<pii> px, py;
    for (int i = 2; 1ll * i * i <= x; i++) {
        if (x % i == 0) {
            int cnt = 0;
            while (x % i == 0) {
                ++cnt;
                x /= i;
            }
            v.push_back(MP(i, cnt));
        }
    }
    
    for (int i = 2; 1ll * i * i <= y; i++) {
        if (y % i == 0) {
            int flag = -1;
            for (int j = 0; j < sz(v); j++) {
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
                px.push_back(MP(i, v[flag].se));
                py.push_back(MP(i, cnt));
            }
        }
    }
    if (x > 1 && x == y) {
        px.push_back(MP(x, 1));
        py.push_back(MP(x, 1));
    }
    int ans = 1;
    for (int k = 0; k < sz(px); k++) {
        int p = px[k].fi;
        int c1 = px[k].se, c2 = py[k].se;
        cout << p << ' ' << c1 << ' ' << c2 << '\n';
        for (int i = a; i <= b; i++) {
            int least = max(c, ((i * c1 + c2 - 1) / c2));
            if (least > d) break;
            // cout << d - least + 1 << ' ' << i * c1 << '\n';
            ans = 1ll * ans * qpow(qpow(p, i * c1), d - least + 1) % MOD;
        }
        // cout << ans << '\n';
        for (int i = c; i <= d; i++) {
            int least = (i * c2 + c1 - 1) / c1;
            if ((i * c2) % c1 == 0) ++least;
            least = max(least, a);
            if (least > b) break;
            // cout << b - least + 1 << ' ' << i * c2 << '\n';
            ans = 1ll * ans * qpow(qpow(p, i * c2), (b - least + 1)) % MOD;
        }
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
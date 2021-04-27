// Author : heyuhhh
// Created Time : 2021/03/20 20:51:17
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
const int N = 1e5 + 5;
void run() {
    int n;
    cin >> n;
    vector<ll> a(n), t(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> t[i];
    }
    int q;
    cin >> q;
    vector<pair<ll, int>> x(q << 1);
    for (int i = 0; i < q; i++) {
        cin >> x[i].fi;
        x[i].se = i;
    }
    
    set<pair<ll, int>> S;
    for (int i = 0; i < q; i++) {
        S.emplace(x[i].fi, x[i].se);
    }

    vector<int> f(q << 1);
    for (int i = 0; i < q << 1; i++) {
        f[i] = i;
    }
    auto find = [&] (int x) {
        while (x != f[x]) {
            int t = f[x];
            f[x] = f[f[x]];
            x = t;
        }
        return x;
    };
    auto Union = [&] (int x, int y) {
        x = find(x), y = find(y);
        if (x != y) f[x] = y;
    };
    ll add_s = 0;
    int tot = q;
    for (int i = 0; i < n; i++) {
        if (t[i] == 1) {
            add_s += a[i];
        }
        if (t[i] == 2) {
            bool f = false;
            while (!S.empty() && S.begin()->fi + add_s <= a[i]) {
                auto it = S.begin();
                Union(it->se, tot);
                S.erase(it);
                f = true;
            }
            if (f) {
                S.emplace(a[i] - add_s, tot);
                x[tot] = MP(a[i] - add_s, tot);
                tot++;
            }
        }
        if (t[i] == 3) {
            bool f = false;
            while (!S.empty()) {
                auto it = S.end(); --it;
                if (it->fi + add_s >= a[i]) {
                    Union(it->se, tot);
                    S.erase(it);
                    f = true;
                } else {
                    break;
                }
            }
            if (f) {
                // cout << a[i] << ' ' << add_s << endl;
                S.emplace(a[i] - add_s, tot);
                x[tot] = MP(a[i] - add_s, tot);
                tot++;
            }
        }
    }
    vector<ll> ans(q);
    for (int i = 0; i < q; i++) {
        int fa = find(i);
        ans[x[i].se] = x[fa].fi + add_s;
    }
    for (int i = 0; i < q; i++) {
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
    run();
    return 0;
}
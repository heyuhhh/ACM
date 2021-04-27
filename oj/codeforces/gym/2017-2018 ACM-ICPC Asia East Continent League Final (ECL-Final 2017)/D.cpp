// Author : heyuhhh
// Created Time : 2021/04/14 09:34:10
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

int _;

ll con(ll x, ll y) {
    vector<int> pos;
    ll t = y;
    while (t) {
        pos.emplace_back(t % 10);
        t /= 10;
    }
    reverse(all(pos));
    for (auto& it : pos) {
        x = x * 10 + it;
    }
    return x;
}

ll calc(ll R) {
    if (R <= 0) return 0;
    vector<int> pos;
    ll t = R;
    while (t) {
        pos.emplace_back(t % 10);
        t /= 10;
    }
    reverse(all(pos));
    ll nw = 0;
    ll res = 0;
    for (int i = 0; i < (sz(pos) + 2) / 3; i++) {
        for (int j = (i == 0); j <= pos[i]; j++) {
            ll tmp = nw * 10 + j;
            for (int q = 1;; q++) {
                ll p = q; 
                ll tmp2 = con(tmp, tmp * p);
                if (tmp2 > R) break;
                p *= q;
                ll tmp3 = con(tmp2, tmp * p);
                if (tmp3 > R) break;
                ++res;
                while (1) {
                    p *= q;
                    tmp3 = con(tmp3, tmp * p);
                    if (tmp3 > R) break;
                    ++res;
                }
            }
        }
        nw = nw * 10 + pos[i];
    }
    return res;
}

void run() {
    ++_;
    ll l, r;
    cin >> l >> r;
    cout << "Case #" << _ << ": " << calc(r) - calc(l - 1) << '\n';;
}
int main() {
#ifdef Local
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T; while(T--)
    run();
    return 0;
}
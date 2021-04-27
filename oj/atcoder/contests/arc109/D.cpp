// Author : heyuhhh
// Created Time : 2020/12/04 16:18:45
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
typedef pair<int, pair<int, int>> myp;
//head
const int N = 1e5 + 5;
void run() {
    vector<int> x(3), y(3);
    for (int i = 0 ;i < 3; i++) {
        cin >> x[i] >> y[i];
    }

    auto checkIt = [&] (vector<int> sx, vector<int> sy) {
        map<pii, bool> mp;
        for (int i = 0; i < 3; i++) {
            mp[MP(sx[i], sy[i])] = true;
        }
        int op;
        for (int i = 0; i < 3; i++) {
            if (mp.find(MP(sx[i], sy[i] + 1)) == mp.end()) continue;
            if (mp.find(MP(sx[i] + 1, sy[i])) == mp.end()) continue;
            return MP(0, MP(sx[i], sy[i]));
        }
        for (int i = 0; i < 3; i++) {
            if (mp.find(MP(sx[i], sy[i] - 1)) == mp.end()) continue;
            if (mp.find(MP(sx[i] + 1, sy[i])) == mp.end()) continue;
            return MP(1, MP(sx[i], sy[i]));
        }
        for (int i = 0; i < 3; i++) {
            if (mp.find(MP(sx[i] - 1, sy[i])) == mp.end()) continue;
            if (mp.find(MP(sx[i], sy[i] - 1)) == mp.end()) continue;
            return MP(2, MP(sx[i], sy[i]));
        }
        for (int i = 0; i < 3; i++) {
            if (mp.find(MP(sx[i] - 1, sy[i])) == mp.end()) continue;
            if (mp.find(MP(sx[i], sy[i] + 1)) == mp.end()) continue;
            return MP(3, MP(sx[i], sy[i]));
        }
    };

    auto e = checkIt(x, y);
    int eop = e.fi;
    int ex = e.se.fi, ey = e.se.se;

    auto solve = [&] (vector<int> sx, vector<int> sy) {
        auto s = checkIt(sx, sy);
        int sop = s.fi;
        int x = s.se.fi, y = s.se.se;
        ll res = 0;
        int dMin = min(abs(x - ex), abs(y - ey));
        int dMax = max(abs(x - ex), abs(y - ey));
        if ((ex >= x && ey >= y) || (ex <= x && ey <= y)) {
            if (sop % 2 == 0) {
                res += 3ll * dMin;
            } else {
                res += 2ll * dMin;
            }
        } else {
            if (sop & 1) {
                res += 3ll * dMin;
            } else {
                res += 2ll * dMin;
            }
        }
        res += 2ll * (dMax - dMin);
        if (sop == eop) {}
        else if ((sop & 1) == (eop & 1)) res += 2;
        else res += 1;
        return res;
    };

    vector<int> sx(3), sy(3);
    sx[1] = 1;
    sy[2] = 1;
    ll ans = solve(sx, sy);

    sx[2] = 1;
    ans = min(ans, 1 + solve(sx, sy));
    sy[2] = -1;
    ans = min(ans, 1 + solve(sx, sy));
    sx[2] = 0;
    ans = min(ans, 1 + solve(sx, sy));
    sy[2] = 1;

    sy[1] = 1;
    ans = min(ans, 1 + solve(sx, sy));
    sx[1] = -1;
    ans = min(ans, 1 + solve(sx, sy));
    sy[1] = 0;
    ans = min(ans, 1 + solve(sx, sy));
    sx[1] = 1;

    sx[0] = sy[0] = 1;
    ans = min(ans, 1 + solve(sx, sy));
    cout << ans << '\n';
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T; while(T--)
    run();
    return 0;
}
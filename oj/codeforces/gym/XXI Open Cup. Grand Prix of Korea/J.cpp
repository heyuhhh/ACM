// Author : heyuhhh
// Created Time : 2020/11/09 10:48:35
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
const int N = 3e5 + 5;

void run() {
    int n, q;
    cin >> n;
    string s;
    cin >> s;
    cin >> q;
    vector<int> x(q), y(q);
    map<pii, int> mp;
    vector<int> f(q);
    iota(all(f), 0);
    for (int i = 0; i < q; i++) {
        cin >> x[i] >> y[i];
        if (mp.find(MP(x[i], y[i])) == mp.end()) {
            mp[MP(x[i], y[i])] = i;
        } else {
            f[i] = mp[MP(x[i], y[i])];
        }
    }
    auto find = [&] (int x) {
        int t = x;
        while (t != f[t]) t = f[t];
        while (x != t) {
            int fa = f[x];
            f[x] = t;
            x = fa;
        }
        return t;
    };
    int dx = 0, dy = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') ++dx;
        if (s[i] == 'U') ++dy;
        if (s[i] == 'D') --dy;
        if (s[i] == 'L') --dx;
        if (mp.find(MP(-dx, -dy)) != mp.end()) {
            int x = mp[MP(-dx, -dy)];
            mp.erase(MP(-dx, -dy));
            int nx = -dx, ny = -dy;
            if (s[i] == 'R') --nx;
            if (s[i] == 'U') --ny;
            if (s[i] == 'D') ++ny;
            if (s[i] == 'L') ++nx;
            if (mp.find(MP(nx, ny)) != mp.end()) {
                int y = mp[MP(nx, ny)];
                f[x] = y;
            } else {
                mp[MP(nx, ny)] = x;
            }
        }
    }
    vector<int> ansx(q), ansy(q);
    for (auto it : mp) {
        int x = it.fi.fi, y = it.fi.se;
        int i = it.se;
        ansx[i] = x, ansy[i] = y;
    }
    for (int i = 0; i < q; i++) {
        ansx[i] = ansx[find(i)], ansy[i] = ansy[find(i)];
    }
    for (int i = 0; i < q; i++) {
        cout << ansx[i] + dx << ' ' << ansy[i] + dy << '\n';
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
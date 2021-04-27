// Author : heyuhhh
// Created Time : 2021/02/25 15:16:16
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
int v[N << 2], mp[N << 2], rmp[N];
pii operator * (int A, pii B) {
    return MP(A * B.fi, A * B.se);
};
void run() {
    int A, B;
    cin >> A >> B;
    int n = A + B;
    
    function<void(int, int)> copy = [&] (int o, int last) {
        v[o] = v[last];
        if (v[last << 1] != 0) copy(o << 1, last << 1);
        if (v[last << 1|1] != 0) copy(o << 1|1, last << 1|1);
    };
    function<pii(int, int, int)> solve = [&] (int o, int x, int y) {
        // cout << o << ' ' << x << ' ' << y << endl;
        pii t = MP(0, 0);
        if (x & 1) {
            if (y & 1) {
                v[o] = 2;
                t = 2 * solve(o << 1, x / 2, y / 2);
                copy(o << 1|1, o << 1);
                ++t.fi;
            } else {
                v[o] = 1;
                t = 2 * solve(o << 1, x / 2, y / 2);
                copy(o << 1|1, o << 1);
            }
        } else {
            if (y & 1) {
                v[o] = 2;
                t = 2 * solve(o << 1, x / 2, y / 2);
                copy(o << 1|1, o << 1);
            } else {
                if (x == 0) {
                    if (y == 0) return t;
                    v[o] = 2;
                    --y;
                    t = 2 * solve(o << 1, x / 2, y / 2);
                    copy(o << 1|1, o << 1);
                    ++t.se;
                } else {
                    v[o] = 1;
                    --x;
                    t = 2 * solve(o << 1, x / 2, y / 2);
                    copy(o << 1|1, o << 1);
                    ++t.fi;
                }
            }
        }
        return t;
    };
    pii tmp = solve(1, A, B);
    int r = tmp.fi, r2 = tmp.se;
    int d = 1;
    while ((1 << (d + 1)) - 1 <= n) ++d;
    int t = (1 << d - 1);
    int siz = t;
    for (int i = t; i < t + siz; i++) {
        if (!v[i << 1] && !v[i << 1|1]) if (r) {
            // cout << i << endl;
            --r;
            v[i << 1] = 1;
            if (r) {
                --r;
                v[(i << 1) + siz] = 1;
            }
        }
    }
    for (int i = t; i < t + siz; i++) if (r2) {
        if (v[i << 1] && !v[i << 1|1]) {
            --r2;
            v[i << 1|1] = 2;
            if (r2) {
                --r2;
                v[(i << 1|1) + siz] = 2;
            }
        }
    }
    for (int i = t; i < t + siz; i++) if (r) {
        if (v[i << 1] && !v[i << 1|1]) {
            --r;
            v[i << 1|1] = 1;
            if (r) {
                --r;
                v[(i << 1|1) + siz] = 1;
            }
        }
    }
    if (r2) {
        cout << -1 << '\n';
        return;
    }
    t <<= 1, siz <<= 1;
    for (int i = t; i < t + siz; i++) if (r) {
        if (v[i << 1] && !v[i << 1|1]) {
            --r;
            v[i << 1|1] = 1;
            if (r) {
                --r;
                v[(i << 1|1) + siz] = 1;
            }
        }        
    }
    int tot = 0;
    for (int i = 1; i < N << 2; i++) {
        if (v[i]) {
            mp[i] = ++tot;
            rmp[tot] = i;
        }
    }
    assert(tot == n);
    for (int i = 1; i <= n; i++) {
        int id = rmp[i];
        cout << v[id] << ' ';
        cout << mp[id << 1] << ' ' << mp[id << 1|1] << '\n';
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
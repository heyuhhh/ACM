// Author : heyuhhh
// Created Time : 2020/08/11 20:12:19
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
typedef pair<ll, pii> edges;
void run() {
    int n;
    cin >> n;
    vector<pii> P(n);
    for (int i = 0; i < n; i++) {
        cin >> P[i].fi >> P[i].se;
    }
    auto sqr = [&](ll x) {
        return x * x;
    };
    auto calc = [&](pii A, pii B) {
        return sqr(A.fi - B.fi) + sqr(A.se - B.se);
    };
    vector<edges> dis;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            dis.push_back(edges{calc(P[i], P[j]), MP(i, j)});
        }
    }
    sort(all(dis), [&](edges A, edges B) {
        return A.fi > B.fi;
    });
    vector<bool> del(n);
    ll now = -1;
    for (int i = 0; i < sz(dis); i++) {
        if (del[dis[i].se.fi] || del[dis[i].se.se]) continue;
        del[dis[i].se.fi] = 1;
        del[dis[i].se.se] = 1;
    }
    if (!del[0]) {
        cout << "NO" << '\n';
    } else {
        cout << "YES" << '\n';
    }
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
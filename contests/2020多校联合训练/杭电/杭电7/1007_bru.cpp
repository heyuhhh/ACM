// Author : heyuhhh
// Created Time : 2020/08/11 13:07:32
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
const int N = 2000 + 5;
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
    vector<ll> Mdis(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (calc(P[i], P[j]) >= Mdis[i]) {
                Mdis[i] = calc(P[i], P[j]);
            }
        }
    }
    vector<bool> vis(n);
    function<void(int, ll, int)> dfs = [&](int u, ll d, int cur) {
        cout << u << endl;
        vis[u] = 1;
        int choose = 0;
        for (int i = 0; i < n; i++) {
            if (i != u && !vis[i] && calc(P[u], P[i]) > d) {
                ++choose;
                dfs(i, calc(P[u], P[i]), cur ^ 1);
            }
        }
        vis[u] = 0;
        if (choose == 0 && cur == 0) {
            
        }
        return;
    };
    dfs(0, -1, 1);
    cout << "NO" << '\n';
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
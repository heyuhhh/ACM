// Author : heyuhhh
// Created Time : 2020/07/30 16:14:34
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
typedef pair<int, ll> pii;
//head
const int N = 1e5 + 5;

typedef vector<pii> Poly;

pii operator * (const pii& A, const pii& B) {
    return MP(A.fi + B.fi, A.se + B.se);
}

Poly operator * (const Poly& A, const Poly& B) {
    Poly C;
    for (int i = 0; i < sz(A); i++) {
        for (int j = 0; j < sz(B); j++) {
            pii tmp = A[i] * B[j];
            C.emplace_back(tmp);
        }
    }
    return C;
}

void run() {
    int n, m;
    cin >> n >> m;
    Poly res(1, MP(0, 0));
    for (int i = 0; i < n; i++) {
        int w, v;
        cin >> w >> v;
        Poly A(2);
        A[0] = MP(0, 0);
        A[1] = MP(w, v);
        res = res * A;
    }
    // for (auto it : res) {
    //     cout << it.fi << ' ' << it.se << '\n';
    // }
    Poly res2(1, MP(0, 0));
    for (int i = 0; i < m; i++) {
        int w, v;
        cin >> w >> v;
        Poly A(2);
        A[0] = MP(0, 0);
        A[1] = MP(w, v);
        res2 = res2 * A;
    }
    unordered_map<int, ll> mp;
    for (auto& it : res2) {
        if (mp.find(it.fi) == mp.end()) {
            mp[it.fi] = it.se;
        } else {
            mp[it.fi] = max(mp[it.fi], it.se);
        }
    }
    ll ans = 0;
    for (auto& it : res) {
        if (mp.find(it.fi) != mp.end()) {
            ans = max(ans, mp[it.fi] + it.se);
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
    int T; cin >> T; while(T--)
    run();
    return 0;
}
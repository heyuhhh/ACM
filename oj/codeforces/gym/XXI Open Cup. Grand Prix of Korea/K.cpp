// Author : heyuhhh
// Created Time : 2020/11/08 12:55:33
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
    vector<pair<pii, int>> a;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a.emplace_back(make_pair(make_pair(x, y), i + 1));
    }
    sort(all(a), [&] (pair<pii, int> A, pair<pii, int> B) {
        if (A.fi.fi != B.fi.fi) return A.fi.fi < B.fi.fi;
        return A.fi.se < B.fi.se;
    });
    vector<int> res;
    for (int i = 1; i <= n; i++) {
        res.emplace_back(a[i - 1].se);
    }
    for (int i = n - 1; i >= 1; i--) {
        res.emplace_back(a[i - 1].se);
    }
    cout << sz(res) << '\n';
    for (auto it : res) {
        cout << it << ' ';
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

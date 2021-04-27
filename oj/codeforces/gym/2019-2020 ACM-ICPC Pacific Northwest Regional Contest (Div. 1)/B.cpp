// Author : heyuhhh
// Created Time : 2020/09/26 15:19:59
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> x(k, INF), y(k, -INF);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        --a[i];
        x[a[i]] = min(x[a[i]], i);
        y[a[i]] = max(y[a[i]], i);
    }
    vector<int> cnt(n);
    vector<vector<int>> v(n);
    for (int i = 0; i < k; i++) {
        ++cnt[y[i]];
        v[x[i]].emplace_back(i);
        // cout << x[i] << ' ' << y[i] << endl;
    }
    set<int> s;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        for (auto it : v[i]) {
            s.insert(it);
        }
        while (cnt[i]) {
            // cout << i << endl;
            auto it = s.begin();
            ans.emplace_back(*it);
            --cnt[y[*it]];
            s.erase(it);
        }
    }
    while (!s.empty()) {
        ans.emplace_back(*s.begin());
        s.erase(s.begin());
    }
    for (int i = 0; i < k; i++) {
        if (i) cout << ' ';
        cout << ans[i] + 1;
    }
    cout << '\n';
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
// Author : heyuhhh
// Created Time : 2021/02/06 22:05:58
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
    vector<int> b(n);
    map<int, bool> used;
    set<int> s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        b[i] = x;
        s.insert(x);
        used[x] = true;
    }
    sort(all(b));
    b.erase(unique(all(b)), b.end());
    n = sz(b);
    int Min = *min_element(all(b));

    set<int> res;
    int flag = 0;
    while (sz(s) > 1) {
        vector<int> a;
        for (auto it : s) a.emplace_back(it);
        s.clear();
        int m = sz(a);
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                int g = __gcd(a[i], a[j]);
                if (g == 1) {
                    flag = 1;
                    continue;
                }
                s.insert(g);
                if (g <= Min) res.insert(g);
            }
        }
    }
    res.insert(Min);
    if (flag) res.insert(1);
    int ans = sz(res);
    cout << ans << '\n';
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
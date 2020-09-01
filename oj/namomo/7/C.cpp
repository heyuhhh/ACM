// Author : heyuhhh
// Created Time : 2020/08/29 19:40:16
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
const int N = 2e5 + 5;
void run() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int Min = *min_element(all(a)), Max = *max_element(all(a));
    bool same = (Min == Max);
    if (same) {
        cout << 0 << '\n';
        return;
    }

    int ans = 0;
    map<int, map<int, int>> mp;
    for (int i = 0; i < n; i++) {
        int& x = a[i];
        int now = 0;
        mp[i][x] = 0;
        while ((int)sqrt(x + 0.5) >= 2) {
            x = (int)sqrt(x + 0.5);
            ++now;
            ++ans;
            mp[i][x] = now;
        }
        if (x != 1) ++ans;
    }

    bool flag = false;
    for (int i = 1; i < n; i++) 
        if (a[i] != a[i - 1]) 
            flag = true;
    if (Min == 1 || flag) {
        cout << ans << '\n';
        return;
    }

    vector<int> best(n);
    ll x = a[0];
    int now = 0;
    while (x <= Max) {
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (mp[i].find(x) != mp[i].end()) {
                best[i] = mp[i][x];
            } else {
                ++best[i];
            }
            res += best[i];
        }
        ans = min(ans, res);
        x = x * x;
        ++now;
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
    run();
    return 0;
}
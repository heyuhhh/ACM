// Author : heyuhhh
// Created Time : 2020/08/15 13:19:56
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
    vector<string> s(n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> a[i];
        a[i] *= 100;
    }
    auto getMax = [&](int x) {
        return min(10000, x + 49);
    };
    auto getMin = [&](int x) {
        return max(0, x - 50);
    };
    
    int Max = 0, Min = 0;
    for (int i = 0; i < n; i++) {
        Max += getMax(a[i]);
        Min += getMin(a[i]);
    }
    if (Min > 10000 || Max < 10000) {
        cout << "IMPOSSIBLE" << '\n';
        return;
    }

    vector<pii> ans(n);

    for (int i = 0; i < n; i++) {
        int all, d;
        int x, y;
        all = getMin(a[i]) + Max - getMax(a[i]);
        d = max(0, 10000 - all);
        x = getMin(a[i]) + d;

        all = getMax(a[i]) + Min - getMin(a[i]);
        d = max(0, all - 10000);
        y = getMax(a[i]) - d;

        if (y - x + 1 > 100 || x > y) {
            cout << "IMPOSSIBLE" << '\n';
            return;
        }
        ans[i] = MP(x, y);
    }

    for (int i = 0; i < n; i++) {
        cout << s[i] << ' ';
        cout << 1.0 * ans[i].fi / 100 << ' ' << 1.0 * ans[i].se / 100 << '\n';
    }
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(2);
    run();
    return 0;
}
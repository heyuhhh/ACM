// Author : heyuhhh
// Created Time : 2020/07/16 17:26:46
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
    int n, p; cin >> n >> p;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(all(a));
    int Max = a[n - 1], Min = a[0];
    int s = max(1, Max - 200000);
    int L = INF, R = 0;
    for (int i = 0; i < n; i++) {
        L = min(L, a[i] - i - 1);
        R = max(R, a[i] - i - 1);
    }
    vector<int> ans;
    for (int x = Min; x < Max; x++) {
        int t = upper_bound(all(a), x) - a.begin();
        int l = t + x - (R + t);
        int r = t + x - (L + t);
        if (r <= 0) continue;
        assert(l <= r);
        cout << x << ' ' << l << ' ' << r << '\n';
        if (l / p == r / p && l % p > 0) {
            ans.push_back(x);
        }
    }
    cout << sz(ans) << '\n';
    for (auto it : ans) {
        cout << it << ' ';
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
// Author : heyuhhh
// Created Time : 2020/08/23 14:31:10
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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> p(n);
    iota(all(p), 0);
    sort(all(p), [&] (int i, int j) {
        return a[i] < a[j];
    });
    if (a[p[0]] + a[p[1]] <= a[p[n - 1]]) {
        vector<int> ans{p[0], p[1], p[n - 1]};
        sort(all(ans));
        for (auto it : ans) cout << it + 1 << ' ';
        cout << '\n';
    } else {
        cout << -1 << '\n';
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
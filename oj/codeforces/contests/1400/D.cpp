// Author : heyuhhh
// Created Time : 2020/08/25 23:56:48
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
        --a[i];
    }
    vector<vector<int>> f(n, vector<int>(n));
    vector<vector<int>> g(n, vector<int>(n));
    vector<ll> h(n);
    ll ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 2; j < n - 1; j++) {
            if (a[i] == a[j]) {
                ans += h[j];
            }
        }
        for (int j = i + 1; j < n; j++) {
            h[j] += g[j][a[i]];
            ++g[i][a[j]];
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
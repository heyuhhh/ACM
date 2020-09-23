// Author : heyuhhh
// Created Time : 2020/09/12 21:51:57
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
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(all(a));
    ll ans = 1;
    for (int i = n - 1; i >= n - 5; i--) 
        ans *= a[i];
    ll res = a[0] * a[1] * a[n - 1] * a[n - 2] * a[n - 3];
    res = max(res, a[0] * a[1] * a[2] * a[3] * a[n - 1]);
    ans = max(ans, res);
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
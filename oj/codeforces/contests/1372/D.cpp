// Author : heyuhhh
// Created Time : 2020/07/12 10:41:07
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
    vector<int> a(n + n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    vector<ll> sum0(n + n), sum1(n + n);
    sum0[0] = a[0];
    sum1[1] = a[1];
    for (int i = 2; i < n + n; i += 2) {
        sum0[i] = sum0[i - 2] + a[i];
    }
    for (int i = 3; i < n + n; i += 2) {
        sum1[i] = sum1[i - 2] + a[i];
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll res = a[i];
        if (i & 1) {
            res += sum1[i + n - 1] - sum1[i];
        } else {
            res += sum0[i + n - 1] - sum0[i];
        }
        ans = max(ans, res);
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
// Author : heyuhhh
// Created Time : 2020/08/23 14:40:33
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
    string s;
    cin >> s;
    vector<int> sum(n);
    sum[0] = s[0] - '0';
    for (int i = 1; i < n; i++) {
        sum[i] = sum[i - 1] + (s[i] - '0');
    }
    ll ans = 0;
    map<int, int> mp;
    mp[0] = 1;
    for (int i = 0; i < n; i++) {
        ans += mp[sum[i] - i - 1];
        ++mp[sum[i] - i - 1];
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
// Author : heyuhhh
// Created Time : 2020/08/23 14:36:53
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
    string s;
    cin >> s;
    s += "&";
    int n = s.length();
    int cnt = (s[0] == '1');

    vector<int> v;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1] && s[i - 1] == '1') {
            v.push_back(cnt);
            cnt = 0;
        } else if (s[i] == s[i - 1] && s[i] == '1') {
            ++cnt;
        } else if (s[i] != s[i - 1] && s[i] == '1') {
            cnt = 1;
        }
    }
    int ans = 0;
    sort(v.rbegin(), v.rend());
    for (int i = 0; i < sz(v); i += 2) {
        ans += v[i];
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
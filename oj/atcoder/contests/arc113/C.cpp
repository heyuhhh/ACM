// Author : heyuhhh
// Created Time : 2021/02/21 20:35:11
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
    int n = s.length();
    vector<int> cnt(26);
    ll ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        ++cnt[s[i] - 'a'];
        if (i + 1 < n && s[i] == s[i + 1]) {
            int all = n - i;
            ans += all - cnt[s[i] - 'a'];
            for (int j = 0; j < 26; j++) {
                cnt[j] = 0;
            }
            cnt[s[i] - 'a'] = all;
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
    run();
    return 0;
}
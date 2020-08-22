// Author : heyuhhh
// Created Time : 2020/08/09 19:31:18
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
    string s, t;
    cin >> s >> t;
    for (int i = 0; i < 100; i++) {
        s += "0", t += "0";
    }
    n += 100;
    vector<int> pre(n), suf(n);
    pre[0] = (t[0] == '1');
    for (int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + (t[i] == '1');
    }
    suf[n - 1] = (s[n - 1] != t[n - 1]);
    for (int i = n - 2; i >= 0; i--) {
        suf[i] = suf[i + 1] + (s[i] != t[i]);
    }
    int ans = suf[0];
    int tot = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            int res = 0;
            if (i) res += pre[i - 1];
            if (i < n - 1) res += suf[i + 1];
            if (t[i] == '0') ++res;
            ans = min(ans, res + tot + 1);
            ++tot;
        } else {
            int res = 0;
            if (i) res += pre[i - 1];
            if (i < n - 1) res += suf[i + 1];
            if (t[i] == '0') ++res;
            ans = min(ans, res + tot + 2);
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
// Author : heyuhhh
// Created Time : 2020/08/25 23:13:57
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
    int x;
    cin >> x;
    for (int k = 0; k < x; k++) {
        string t = "";
        for (int i = k; i < n; i += x) {
            t += s[i];
        }
        
        int m = t.length();
        string res(m, '1');
        for (int i = 0; i < m; i++) {
            if (t[i] == '0') {
                if (i) res[i - 1] = '0';
                if (i + 1 < m) res[i + 1] = '0';
            }
        }
        // cout << t << ' ' << res << '\n';
        for (int i = 0; i < m; i++) {
            if (t[i] == '0') {
                if (i && res[i - 1] != '0') {
                    cout << -1 << '\n';
                    return;
                }
                if (i + 1 < m && res[i + 1] != '0') {
                    cout << -1 << '\n';
                    return;
                }
            } else {

                if ((i == 0 || res[i - 1] == '0') && (i == m - 1 || res[i + 1] == '0')) {
                    cout << -1 << '\n';
                    return;
                }
            }
        }
        for (int i = k, j = 0; i < n; i += x, j++) {
            s[i] = res[j];
        }
    }
    cout << s << '\n';
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
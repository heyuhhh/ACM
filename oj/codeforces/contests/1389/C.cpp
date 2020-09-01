// Author : heyuhhh
// Created Time : 2020/08/23 10:31:40
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
    int ans = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) if (i != j) {
            int cnt = 0;
            for (int k = 0; k < n; k++) {
                if (cnt & 1) {
                    if (s[k] - '0' == j) ++cnt;
                } else {
                    if (s[k] - '0' == i) ++cnt;
                }
            }
            cnt -= (cnt & 1);
            ans = max(ans, cnt);
        }
    }

    vector<int> cnt(10);
    for (int i = 0; i < n; i++) {
        ++cnt[s[i] - '0'];
    }
    for (int i = 0; i < 10; i++) {
        ans = max(ans, cnt[i]);
    }
    cout << n - ans << '\n';
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
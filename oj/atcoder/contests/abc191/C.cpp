// Author : heyuhhh
// Created Time : 2021/02/06 20:09:40
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
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int ans = 0;
    int pre = 0;
    for (int i = 0; i + 1 < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] != s[i + 1][j]) {
                ++pre;
            } else {
                if (pre > 0) {
                    ++ans;
                    pre = 0;
                }
            }
        }
        if (pre > 0) {
            ++ans;
            pre = 0;
        }
    }
    for (int j = 0; j + 1 < m; j++) {
        for (int i = 0; i < n; i++) {
            if (s[i][j] != s[i][j + 1]) {
                ++pre;
            } else {
                if (pre > 0) {
                    ++ans;
                    pre = 0;
                }
            }
        }
        if (pre > 0) {
            ++ans;
            pre = 0;
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
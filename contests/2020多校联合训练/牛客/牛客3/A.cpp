// Author : heyuhhh
// Created Time : 2020/07/18 12:23:24
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
    int ans = 0;
    int p = 0;
    int d = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            if (p > d) {
                --p;
                ++ans;
            } else if (d > 0) {
                --d;
                ++ans;
            }
        } else if (s[i] == '1') {
            if (p > d) {
                //make it clam and use it later
                ++d;
            } else {
                ++p;
            }
        } else {
            ++ans;
        }
    }
    ans += d;
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
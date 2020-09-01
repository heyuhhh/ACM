// Author : heyuhhh
// Created Time : 2020/07/17 13:18:38
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
    int c2 = 0, c3 = 0;
    while (n % 2 == 0) {
        n /= 2;
        ++c2;
    }
    while (n % 3 == 0) {
        n /= 3;
        ++c3;
    }
    if (n != 1) {
        cout << -1 << '\n';
    } else {
        if (c2 > c3) {
            cout << -1 << '\n';
        } else {
            int ans = c3 - c2 + c3;
            cout << ans << '\n';
        }
    }
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
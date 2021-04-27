// Author : heyuhhh
// Created Time : 2021/03/14 15:24:47
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
    vector<int> a(n);
    vector<int> b;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int last = -1;
    for (int i = 1; i < n; i++) if (a[i] != a[i - 1]) {
        if (a[i] < a[i - 1]) {
            if (last != 0) {
                if (last == 1) b.emplace_back(last);
                last = 0;
            }
        } else {
            if (last != 1) {
                if (last == 0) b.emplace_back(last);
                last = 1;
            }
        }
    }
    b.emplace_back(last);
    // for (auto& it : b) {
    //     cout << it << ' ';
    // } cout << '\n';
    int ans = 0;
    for (int i = 0;; i++) {
        if ((1 << i) >= sz(b)) {
            ans = i;
            break;
        }
    }
    if (b[0] == 0 && (1 << ans) == sz(b)) ++ans;
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
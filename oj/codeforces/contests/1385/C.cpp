// Author : heyuhhh
// Created Time : 2020/07/18 09:25:31
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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int flag = 1;
    int ans = -1;
    for (int i = n - 1; i > 0; i--) {
        if (flag) {
            if (a[i] > a[i - 1]) {
                flag = 0;
            }
        } else {
            if (a[i] < a[i - 1]) {
                ans = i - 1;
                break;
            }
        }
    }
    cout << ans + 1 << '\n';
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
// Author : heyuhhh
// Created Time : 2020/08/10 12:23:11
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
    auto check = [&] (int x) {
        ll res = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > x) {
                if (res >= a[i] - x) {
                    res -= a[i] - x;
                } else {
                    return false;
                }
            } else {
                res += x - a[i];
            }
        }
        return res >= 0;
    };
    int l = 1, r = INF, mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l << '\n';
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
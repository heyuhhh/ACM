// Author : heyuhhh
// Created Time : 2021/02/07 13:31:27
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
    sort(all(a));
    vector<int> d;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j * j <= a[i]; j++) {
            if (a[i] % j == 0) {
                if (j <= a[0]) d.emplace_back(j);
                if (a[i] / j <= a[0]) d.emplace_back(a[i] / j);
            }
        }
    }
    sort(all(d));
    d.erase(unique(all(d)), d.end());

    int ans = 0;
    for (auto it : d) {
        int g = 0;
        for (int i = 0; i < n; i++) if (a[i] % it == 0) {
            g = __gcd(g, a[i]);
        }
        if (g == it) ++ans;
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
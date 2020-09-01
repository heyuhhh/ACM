// Author : heyuhhh
// Created Time : 2020/07/17 13:46:58
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
    int n, k; 
    cin >> n >> k;
    vector<int> a;
    vector<int> b;
    vector<int> c;
    for (int i = 0; i < n; i++) {
        int t, x, y;
        cin >> t >> x >> y;
        if (x * y == 1) {
            a.push_back(t);
        } else if (x) {
            b.push_back(t);
        } else if (y) {
            c.push_back(t);
        }
    }
    sort(all(b));
    sort(all(c));
    for (int i = 0; i < min(sz(b), sz(c)); i++) {
        a.push_back(b[i] + c[i]);
    }
    if (sz(a) < k) {
        cout << -1 << '\n';
        return;
    }
    sort(all(a));
    int ans = 0;    
    for (int i = 0; i < k; i++) {
        ans += a[i];
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
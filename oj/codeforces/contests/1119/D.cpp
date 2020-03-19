#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
int n;
ll a[N], s[N], sum[N];

int main() {
    ios::sync_with_stdio(false);cin.tie(0) ;
    cin >> n;
    for(int i = 1 ; i <= n; i++) {
        cin >> a[i] ;
    }
    sort(a + 1 , a + n + 1);
    int l = unique(a + 1, a + n + 1) - a - 1;
    for(int i = 1 ; i < l ; i++) s[i] = a[i + 1] - a[i] ;
    sort(s + 1 , s + l) ;
    for(int i = 1; i < l ; i++) sum[i] =sum[i - 1] + s[i] ;
    int q;
    ll x, y;
    cin >> q;
    while(q--) {
        cin >> x >> y ;
        ll d = y - x + 1;
        int p = upper_bound(s + 1, s + l, d) - s - 1;
        ll ans = sum[p] ;
        ans += 1ll * (l - p) * d;
        cout << ans << ' ' ;
    }
    return 0 ;
}

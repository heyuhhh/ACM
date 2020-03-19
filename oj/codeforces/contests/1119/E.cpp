#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 300005;
int n;
int a[N];
int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n ; i++) cin >> a[i] ;
    ll pairs = 0;
    ll ans = 0;
    for(int i = n ; i >= 1 ;i--) {
        pairs += a[i] / 2;
        if(a[i] & 1 && pairs > 0) {
            ans++;
            pairs--;
        }
    }
    ans += pairs * 2 / 3;
    cout << ans ;
    return 0 ;
}

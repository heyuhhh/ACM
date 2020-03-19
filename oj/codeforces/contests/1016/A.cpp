#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
ll n,m;
ll a[N];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n >> m;
    for (int i = 1;i <= n; i++) {
        cin >> a[i];
    }
    ll sum = 0,last = 0;
    for (int i = 1;i <= n; i++) {
        sum += a[i] ;
        cout << sum / m - last << ' ';
        last = sum / m ;
    }
    return 0;
}

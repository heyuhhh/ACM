#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3 + 5;
int n, h;
int a[N], b[N];
bool check(int x) {
    for(int i = 1; i <= x ; i++) b[i] = a[i];
    sort(b + 1, b + x + 1) ;
    int tmp = h;
    for(int i = x; i >= 1; i -= 2) {
        int j = max(1, i - 1) ;
        tmp -= max(b[i], b[j]) ;
        if(tmp < 0) break ;
    }
    return tmp >= 0;
}
int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n >> h;
    for(int i = 1; i <= n ;i++)
        cin >> a[i] ;
    int l = 0, r = n + 1, mid ;
    while(l < r) {
        mid = (l + r) >> 1;
        if(check(mid)) l = mid + 1;
        else r = mid;
    }
    cout << l - 1;
    return 0 ;
}

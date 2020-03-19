#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5 + 5;
int n;
int c[N];
int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n ;i++) {
        cin >> c[i] ;
    }
    int ans = 0;
    for(int i = 2; i <= n ;i++) {
        if(c[i] != c[1]) ans=max(i - 1, ans);
    }
    for(int i = n - 1; i >= 1; i--) {
        if(c[i] != c[n]) ans=max(n - i, ans);
    }
    cout << ans;
    return 0 ;
}

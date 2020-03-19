#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 505;
int a[N][N], b[N][N] ;
int n, m ;
int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n >> m ;
    for(int i = 1; i <= n ; i++) {
        for(int j = 1 ; j <= m ; j++) {
            cin >> a[i][j] ;
        }
    }
    for(int i = 1; i <= n ; i++) {
        for(int j = 1 ; j <= m ; j++) {
            cin >> b[i][j] ;
        }
    }
    int f = 0;
    for(int i = 1 ; i <= n ; i++) {
        int cnt1 = 0 , cnt2 = 0;
        for(int j = 1; j <= m ; j++) {
            if(a[i][j]) cnt1++;
            if(b[i][j]) cnt2++;
        }
        if((cnt1 & 1) != (cnt2 & 1)) f = 1;
    }
    for(int i = 1 ; i <= m ; i++) {
        int cnt1 = 0 , cnt2 = 0;
        for(int j = 1; j <= n ; j++) {
            if(a[j][i]) cnt1++;
            if(b[j][i]) cnt2++;
        }
        if((cnt1 & 1) != (cnt2 & 1)) f = 1;
    }
    if(f) cout << "No" ;
    else cout << "Yes" ;
    return 0;
}

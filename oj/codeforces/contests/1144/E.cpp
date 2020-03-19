#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
int n;
char s[3][N];
int d[N];
int main() {
    cin >> n;
    scanf("%s%s",s[0],s[1]);
    for(int k = 0 ; k < 2; k++) {
        for(int i = 0; i < n; i++) {
            d[i] += (s[k][i] - 'a');
        }
    }
    for(int i = n - 1 ; i > 0 ; i--) {
        d[i - 1] += d[i] / 26 ;
        d[i] %= 26;
    }
    for(int i = 0 ; i < n - 1 ; i++) {
        if(d[i] & 1) d[i + 1] += 26;
        d[i] /= 2;
    }
    d[n - 1] /= 2;
    for(int i = 0 ; i < n ; i++) {
        cout <<char( d[i] + 'a' );
    }
    return 0 ;
}

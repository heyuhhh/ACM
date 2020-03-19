#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 205;
int n;
char s[N];
int main() {
    cin >> n;
    for(int i = 1; i <= n ;i++) {
        scanf("%s",s);
        int l = strlen(s);
        if(l == 1) {
            cout << "YES" << '\n';
            continue ;
        }
        sort(s,s+l);
        int f = 0;
        for(int j = 1; j < l ; j++) {
            if(s[j]==s[j-1]+1) f = 1 ;
            else{
                f = 0;
                break ;
            }
        }
        if(f) cout << "YES" <<'\n';
        else cout << "NO" << '\n';
    }
    return 0;
}

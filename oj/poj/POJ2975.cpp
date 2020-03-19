#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int n;
ll a[N];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    while(cin>>n && n){
        ll x = 0;
        for(int i=1;i<=n;i++) cin>>a[i],x^=a[i];
        int ans = 0;
        for(int i=1;i<=n;i++){
            if((a[i]^x)<a[i]) ans++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}

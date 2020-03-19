#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int n;
int l[N],r[N];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>l[i]>>r[i];
    int k;
    cin>>k;
    int p = lower_bound(l+1,l+n+1,k)-l;
    if(l[p]==k) cout<<n-p+1;
    else cout<<n-p+2;
    return 0;
}

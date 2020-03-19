#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5+5;
ll a[N];
int n;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%I64d",&a[i]);
    sort(a+1,a+n+1);
    ll ans =0 ;
    for(int i=1;i<=n/2;i++){
        int j = n-i+1;
        ans+=(a[i]+a[j])*(a[i]+a[j]);
    }
    cout<< ans;
    return 0;
}

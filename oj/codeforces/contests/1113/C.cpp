#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int cnt[2][1<<20];
int main(){
    int n;
    cin>>n;
    vector <ll> a(n+2);
    for(int i=1;i<=n;i++) scanf("%I64d",&a[i]);
    ll sum=0,ans=0;
    cnt[0][0]=1;
    for(int i=1;i<=n;i++){
        sum^=a[i];
        ans+=cnt[i%2][sum];
        cnt[i%2][sum]++;
    }
    cout<<ans;
    return 0;
}

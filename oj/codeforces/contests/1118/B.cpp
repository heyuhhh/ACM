#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int n;
int a[N];
ll pre[N],sub[N];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    ll sum1=0,sum2=0;
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1];
        sub[i]=sub[i-1];
        if(i&1) pre[i]+=a[i];
        else sub[i]+=a[i];
    }
    sum1=pre[n];sum2=sub[n];
    ll sum=sum1+sum2;
    ll ans = 0;
    for(int i=1;i<=n;i++){
        ll now =0;
        if(i&1){
            now+=pre[i-1];
            now+=sum-sub[i-1]-sum1;
        }else{
            now+=sub[i-1];
            now+=sum-pre[i-1]-sum2;
        }
        if(now*2==sum-a[i]) ans++;
    }
    cout<<ans;
    return 0;
}

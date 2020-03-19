#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
ll n,m,k;
ll a[N],b[N],c[N];
int main(){
    cin>>n>>m>>k;
    int cnt = 1;
    for(int i=1;i<=n;i++){
        scanf("%I64d",&a[i]);
    }
    for(int i=n;i>=1;i--){
        if(k-b[cnt]>=a[i]){
            c[cnt]++;
            b[cnt]+=a[i];
        }else{
            cnt++;
            c[cnt]=1;
            b[cnt]+=a[i];
        }
    }
    ll ans = 0;
    for(int i=1;i<=m;i++) ans+=c[i];
    cout<<ans;
    return 0;
}

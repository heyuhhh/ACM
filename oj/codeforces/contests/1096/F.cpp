#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5,MOD = 998244353;
int n;
int a[N],c[N],large[N],vis[N];
int lowbit(int x){
    return x&(-x);
}
ll qp(ll A,ll B){
    ll ans=1;
    while(B){
        if(B&1) ans=ans*A%MOD;
        A=A*A%MOD;
        B>>=1;
    }
    return ans ;
}
ll inv(ll x){
    return qp(x,MOD-2);
}
void update(int p,int x){
    for(;p<=n;p+=lowbit(p)) c[p]+=x;
}
ll getsum(int p){
    ll cnt = 0;
    for(;p>0;p-=lowbit(p)) cnt+=c[p];
    return cnt ;
}
int main(){
    scanf("%d",&n);
    ll cnt = 0,ans =0,num;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]==-1) cnt++;
        else vis[a[i]]=1;
    }
    int cur = 0;
    for(int i=n;i>=1;i--){
        large[i]=cur;
        cur+=!vis[i];
    }
//Case1:
    ans=(ans+(cnt-1)*cnt%MOD*inv(4)%MOD)%MOD;
//Case2:
    num = 0;
    for(int i=1;i<=n;i++){
        if(a[i]==-1) num++;
        else{
            ll len = large[a[i]];
            ans=(ans+num*len%MOD*inv(cnt)%MOD)%MOD;
        }
    }
//Case3:
    num = 0;
    for(int i=n;i>=1;i--){
        if(a[i]==-1) num++;
        else{
            ll len = cnt-large[a[i]];
            ans=(ans+num*len%MOD*inv(cnt)%MOD)%MOD;
        }
    }
//Case4:
    for(int i=n;i>=1;i--){
        if(a[i]==-1) continue ;
        ans=(ans+getsum(a[i]))%MOD;
        update(a[i],1);
    }
    cout<<ans;
    return 0;
}

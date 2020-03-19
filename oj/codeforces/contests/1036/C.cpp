#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll C[30][30];
int T;
ll a,b;
int num[30],pow9[30]={1,9,81,729};
ll calc(ll x,ll k){
    ll ans = 0;
    if(x<=0) return 1;
    for(int i=0;i<=k;i++) ans+=C[x][i]*pow9[i];
    return ans ;
}
ll solve(ll x){
    memset(num,0,sizeof(num));
    int n;
    for(n=1;x;n++){
        num[n]=x%10;
        x/=10;
    }
    n--;
    ll ans = 0;
    for(int i=n,cur=3;i>=1;i--){
        if(!num[i]) continue ;
        ans+=calc(i-1,cur);
        cur--;
        ans+=(num[i]-1)*calc(i-1,cur);
        if(cur==0) break ;
        //if(i==1) ans++;
    }
    return ans ;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    C[1][0]=1;C[1][1]=1;
    for(int i=2;i<=20;i++){
        C[i][0]=1;
        for(int j=1;j<=i;j++){
            C[i][j]=C[i-1][j]+C[i-1][j-1];
        }
    }
    cin>>T;
    while(T--){
        cin>>a>>b;
        //cout<<solve(b)<<" "<<solve(a-1)<< '\n';
        cout<<solve(b)-solve(a-1)<< '\n';
    }
    return 0;
}

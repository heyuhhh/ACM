#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353 ,N = 2005;
ll n,m,k;
ll C[N][N];
ll qp(ll a,ll b){
    ll ans = 1;
    while(b){
        if(b&1) ans=(a*ans)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return ans ;
}
int main(){
    cin>>n>>m>>k;
    C[0][0]=C[1][1]=1;
    for(int i=1;i<=n;i++) C[i][0]=1;
    for(int i=2;i<=n;i++)
        for(int j=1;j<=i;j++)
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
    ll ans = (C[n-1][k]*m)%MOD;

    cout<<ans*qp(m-1,k)%MOD<<endl;
    return 0;
}


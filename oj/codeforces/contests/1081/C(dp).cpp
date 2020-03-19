#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353,N = 2005;
ll n,m,k;
ll dp[N][N];
int main(){
    cin>>n>>m>>k;
    dp[1][0]=m;
    for(int i=2;i<=n;i++){
        for(int j=0;j<i;j++){
            dp[i][j]=dp[i-1][j];
            if(j!=0) dp[i][j]=(dp[i][j]+dp[i-1][j-1]*(m-1))%MOD;
        }
    }
    cout<<dp[n][k];
    return 0;
}


#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int N = 205;
int k,n,x;
int a[N];
ll dp[N][N];
int main(){
    scanf("%d%d%d",&n,&k,&x);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    memset(dp,-INF,sizeof(dp));
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=min(i,x);j++){
            for(int p=max(0,i-k);p<=i-1;p++){
                dp[i][j]=max(dp[i][j],dp[p][j-1]+a[i]);
            }
        }
    }
    ll ans = -INF;
    for(int i=n;i>max(0,n-k);i--) ans=max(ans,dp[i][x]);
    if(ans<0) cout<<-1;
    else cout<<ans;
    return 0;
}

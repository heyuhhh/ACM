#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int N = 105;
ll a[N];
ll dp[N][N][N];
char s[N];
int n;
int main(){
    scanf("%d",&n);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++) dp[i][i][1]=a[1];
    for(int i=n-1;i>=1;i--){
        for(int j=i+1;j<=n;j++){
            for(int k=1;k<=j-i;k++)
            dp[i][j][1]=max(dp[i][j][1],dp[i+1][j][k]+a[1]);
            for(int q=i+1;q<=j;q++){
                ll tmp=0;
                if(s[q]!=s[i]) continue ;
                for(int p=1;p<=q-i-1;p++) tmp=max(tmp,dp[i+1][q-1][p]);
                for(int k=2;k<=j-i+1;k++){
                    if(dp[q][j][k-1]) dp[i][j][k]=max(dp[i][j][k],tmp+dp[q][j][k-1]-a[k-1]+a[k]);
                }
            }
        }
    }
    ll ans = 0;
    for(int i=1;i<=n;i++) ans=max(ans,dp[1][n][i]);
    cout<<ans;
    return 0;
}

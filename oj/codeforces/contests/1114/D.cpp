#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int N = 5005;
int n;
int c[N];
int dp[N][N][2];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j][0]=dp[i][j][1]=(i==j)?0:INF;
        }
    }
    for(int k=2;k<=n;k++){
        for(int i=1;i<=n;i++){
            int j=i+k-1;
            if(j>n) break ;
            if(i<n){
                dp[i][j][0]=min(dp[i][j][0],dp[i+1][j][0]+(c[i]!=c[i+1]));
                dp[i][j][0]=min(dp[i][j][0],dp[i+1][j][1]+(c[i]!=c[j]));
            }
            if(j>1){
                dp[i][j][1]=min(dp[i][j][1],dp[i][j-1][0]+(c[j]!=c[i]));
                dp[i][j][1]=min(dp[i][j][1],dp[i][j-1][1]+(c[j]!=c[j-1]));
            }
        }
    }
    int ans=min(dp[1][n][1],dp[1][n][0]);
    cout<<ans;
    return 0;
}

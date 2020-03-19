#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 505,INF = 0x3f3f3f3f3f;
int n;
char s[N];
int dp[N][N];
int main(){
    scanf("%d",&n);
    scanf("%s",s+1);
    memset(dp,INF,sizeof(dp));
    for(int i=1;i<=n;i++) dp[i][i]=1;
    for(int l=2;l<=n;l++){
        for(int i=1;i<=n;i++){
            int j=i+l-1;
            if(j>n) break ;
            for(int k=i;k<j;k++){
                if(s[i]==s[j]) dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]-1);
                else dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
            }
        }
    }
    cout<<dp[1][n];
    return 0;
}

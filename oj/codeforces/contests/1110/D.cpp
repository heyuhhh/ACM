#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+5;
int n,m;
int a[N],dp[N][3][3];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        a[x]++;
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                for(int l=0;l<3;l++){
                    if(l+j+k>a[i]) continue ;
                    dp[i][k][l]=max(dp[i][k][l],dp[i-1][j][k]+l+(a[i]-l-k-j)/3);
                }
            }
        }
    }
    cout<<dp[m][0][0];
    return 0;
}

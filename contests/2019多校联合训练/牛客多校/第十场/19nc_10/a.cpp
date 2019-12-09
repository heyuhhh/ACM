#include<bits/stdc++.h>
using namespace std;
typedef double db;
const int maxn=505;
int d[maxn],n,a,b;
bool op=0;
db f[maxn],nf[maxn],dp[2][maxn][maxn],v[maxn][maxn];
db C(int x,int y){
    return f[x]*nf[y]*nf[x-y];
}
int main(){
    scanf("%d%d%d",&n,&a,&b);
    for (int i=1;i<=n;i++) scanf("%d",&d[i]);
    f[0]=nf[0]=1;
    for (int i=1;i<=n;i++) f[i]=f[i-1]*i,nf[i]=nf[i-1]/i;
    db ans=0;
    memset(dp,0,sizeof(dp));
    dp[0][0][0]=1;
    for (int i=1;i<=n;i++){
        for (int j=0;j<n;j++) for (int k=0;k<=b;k++) dp[op^1][j][k]=dp[op][j][k];
        for (int j=1;j<n;j++) for (int k=d[i];k<=b;k++) dp[op^1][j][k]+=dp[op][j-1][k-d[i]]/(n-j+1)*j;
        op^=1;
    }
    for (int o=1;o<=n;o++){
        for (int j=0;j<n;j++)
        for (int k=0;k<=b;k++) {
            v[j][k]=dp[op][j][k];
            if (j>0&&k>=d[o]) v[j][k]-=v[j-1][k-d[o]]/(n-j+1)*j;
        }
        int l=max(0,a-d[o]+1),r=min(a,b-d[o]);
        for (int i=r;i>=l;i--)
            for (int j=0;j<n;j++)
                ans+=v[j][i]/(n-j);
    }
    assert(isfinite(ans));
    printf("%.12f\n",(double)ans);
    return 0;
}

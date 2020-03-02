#include<bits/stdc++.h>
#define maxn 105
using namespace std;
typedef long long LL;
 
int n;
LL modu;
 
LL dp[maxn][maxn][maxn];
 
void add(LL &a,LL b)    {
    a=(a+b)%modu;
}
 
int main()  {
    scanf("%d%lld",&n,&modu);
 
    dp[1][1][1]=1;
    for (int i=1;i<n;++i)  {
        for (int j=1;j<=i;++j)
            for (int k=1;k<=i;++k)  {
                LL &pre=dp[i][j][k];
                if (!pre) continue;
                if (j<k)   {
                    for (int p=1;p<=j;++p)
                        // cout<<p<<" "<<k<<":"<<pre<<endl,
                        add(dp[i+1][p][k+1],pre);
                    for (int p=i+1;p>k;--p)
                        // cout<<p<<" "<<j<<":"<<pre<<endl,
                        add(dp[i+1][p][j],pre);
                } else if(j > k) {
                    for (int p=1;p<=k;++p)
                        // cout<<p<<" "<<k<<":"<<pre<<endl,
                        add(dp[i+1][p][j+1],pre);
                    for (int p=i+1;p>j;--p)
                        // cout<<p<<" "<<j<<":"<<pre<<endl,
                        add(dp[i+1][p][k],pre);
                }
            }
        // cout<<endl;
    }
     
    LL ans=0;
    for (int j=1;j<=n;++j)
        for (int k=1;k<=n;++k)
            add(ans,dp[n][j][k]);
    printf("%lld\n",ans);
    return 0;
}

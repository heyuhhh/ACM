#include<bits/stdc++.h>
using namespace std;

const int MAXN=53;
const int MAXK=7;
const int Mod=1000000007;

inline int fp(int a,int k)
{
    int res=1;
    if(k<0)a=fp(a,Mod-2),k=-k;
    while(k)
    {
        if(k&1)res=1LL*res*a%Mod;
        a=1LL*a*a%Mod;
        k>>=1;
    }
    return res;
}

int c[MAXN][MAXN],inv[MAXN];
int p[MAXK],sp[MAXK],pwx[MAXN];
int t1[MAXN][MAXN],t2[MAXN][MAXN];
int f[MAXK][MAXN],g[MAXN][MAXN],r[MAXN*MAXK];

vector<int> interpolation(int y[],int n)
{
    vector<int>u(y,y+n),ret(n),sum(n);
    ret[0]=u[0],sum[0]=1;
    for(int i=1; i<n; ++i)
    {
        for(int j=n-1; j>=i; j--)
            u[j]=1LL*(u[j]-u[j-1]+Mod)*fp(i,-1)%Mod;
        for (int j=i; j>0; j--)
        {
            sum[j]=(sum[j-1]-1LL*(i-1)*sum[j]%Mod+Mod)%Mod;
            ret[j]=(ret[j]+1LL*sum[j]*u[i])%Mod;
        }
        sum[0]=1LL*(i-1)*(Mod-sum[0])%Mod;
        ret[0]=(ret[0]+1LL*sum[0]*u[i])%Mod;
    }
    return ret;
}

void solve()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0; i<=k; i++)
        scanf("%d",&p[i]);
    for(int i=0; i<=k; i++)
        p[i]=1LL*p[i]*fp(100,-1)%Mod;
    sp[k+1]=0;
    for(int i=k; i>=0; i--)
        sp[i]=(sp[i+1]+p[i])%Mod;
    for(int x=0; x<=(k-1)*(n-1); x++)
    {
        for(int i=(pwx[0]=1); i<=n; i++)
            pwx[i]=1LL*x*pwx[i-1]%Mod;
        for(int t=0; t<=k; t++)
            for(int i=1; i<=n; i++)
                f[t][i]=0;
        f[0][1]=1;
        for(int t=1; t<=k; t++)
        {
            for(int i=0; i<=n; i++)
                for(int j=0; i+j<=n; j++)
                {
                    t2[i][j]=fp(p[0]+sp[t+1],i*j);
                    t1[i][j]=(fp(p[0]+sp[t],i*j)-t2[i][j]+Mod)%Mod;
                }
            for(int i=1; i<=n; i++)
                for(int j=0; j<=n-i; j++)
                    g[i][j]=(j==0);
            for (int s=1; s<=n; s++)
            {
                f[t][s]=0;
                for(int i=1; i<=s; i++)
                    f[t][s]=(f[t][s]+1LL*f[t-1][i]*g[i][s-i]%Mod*c[s-1][i-1]%Mod)%Mod;
                for(int i=1; i<=n; i++)
                    for(int j=n-i; j>=0; j--)
                        for(int k=1,cof=1,stp=1LL*pwx[t-1]*t1[i][s]%Mod*f[t][s]%Mod; j+k*s<=n-i; k++)
                        {
                            cof=1LL*cof*stp%Mod*t2[j+(k-1)*s][s]%Mod*c[j+k*s][s]%Mod%Mod;
                            g[i][j+k*s]=(g[i][j+k*s]+1LL*g[i][j]*cof%Mod*inv[k])%Mod;
                        }
            }
        }
        r[x]=f[k][n];
    }
    vector<int> res=interpolation(r,(k-1)*(n-1)+1);
    int ans=0;
    for(int i=0; i<=(k-1)*(n-1); i++)
        ans=(ans+1LL*(n-1+i)*res[i])%Mod;
    for(int i=0; i<=(k-1)*(n-1); i++)
        printf("%d%c",res[i]," \n"[i==(k-1)*(n-1)]);
}

void build()
{
    for(int i=(c[0][0]=1); i<MAXN; i++)
        for(int j=(c[i][0]=1); j<=i; j++)
            c[i][j]=(c[i-1][j]+c[i-1][j-1])%Mod;
    for(int i=(inv[0]=1); i<MAXN; i++)
        inv[i]=1LL*i*inv[i-1]%Mod;
    for(int i=0; i<MAXN; i++)
        inv[i]=fp(inv[i],-1);
}

int main()
{
    build();
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}

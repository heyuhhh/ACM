#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const int N=255;
const int MOD=1e9+7;
int add (int x,int y)   {x=x+y;return x>=MOD?x-MOD:x;}
int mul (int x,int y)   {return (LL)x*y%MOD;}
int dec (int x,int y)   {x=x-y;return x<0?x+MOD:x;}
int Pow (int x,int y)
{
    if (y==1) return x;
    int lalal=Pow(x,y>>1);
    lalal=mul(lalal,lalal);
    if (y&1) lalal=mul(lalal,x);
    return lalal;
}
int n,m;
int C[N][N];
int f[N];
int main()
{
    scanf("%d%d",&n,&m);
    if (m==1)
    {
        printf("%d\n",((LL)n*(n+1)/2)%MOD);
        return 0;
    }
    C[0][0]=1;
    for (int u=1;u<=m;u++)
    {
        C[u][0]=1;
        for (int i=1;i<=u;i++)   C[u][i]=add(C[u-1][i-1],C[u-1][i]);
    }
    f[0]=mul(mul(m,dec(1,Pow(m,n))),Pow(dec(1,m),MOD-2));
    int lalal=Pow(m,n+1),inv=Pow(m-1,MOD-2);
     
    for (int u=1;u<=m;u++)
    {
        lalal=mul(lalal,n);
        int cnt=0;
        for (int j=0;j<u;j++)
        {
            int now=mul(C[u][j],f[j]);
            if ((u-j)&1) cnt=dec(cnt,now);
            else cnt=add(cnt,now);
        }
        f[u]=mul(inv,add(lalal,cnt));
    }
    //for(int i = 0; i <= m; i++) printf("%d\n", f[i]);
    printf("%d\n",f[m]);
    return 0;
}

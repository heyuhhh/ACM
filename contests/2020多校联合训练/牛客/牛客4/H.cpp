#include<bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LC k<<1
#define RC k<<1|1
 
typedef long long LL;
const int N=210000;
const int M=1100000;
const LL mod=1e9+7;
 
int T,n;
int prim[1100000],primm;
bool valid[11000000];
void getprime(int n)
{
    memset(valid,1,sizeof(valid));
    valid[1]=false;
    for(int i=2;i<=n;i++)
    {
        if(valid[i]) prim[++primm]=i;
        for(int j=1;j<=n&&i*prim[j]<=n;j++)
        {
            valid[i*prim[j]]=false;
            if(i%prim[j]==0)break;
        }
    }
}
int num;
int pp[N];
vector<int> f[N];
vector<pair<int,int> > ans;
int main()
{
    getprime(400000);
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            pp[i]=0,f[i].clear();
        int l=1;
        while (prim[l+1]<=n) l++;
        for (int i=l;i>=1;i--)
        {
            int p=prim[i];
            while (p<=n)
            {
                if (!pp[p]) f[i].pb(p),pp[p]=1;
                p+=prim[i];
            }
        }
        ans.clear();
        for (int i=l;i>=1;i--)
        {
            if (f[i].size()==1) continue;
            if (f[i].size()%2==0)
            {
                for (int j=0;j<f[i].size();j+=2)
                    ans.pb(mp(f[i][j],f[i][j+1]));
            }
            else
            {
                ans.pb(mp(f[i][0],f[i][2]));
                for (int j=3;j<f[i].size();j+=2)
                    ans.pb(mp(f[i][j],f[i][j+1]));
                if (i!=1) f[1].pb(f[i][1]);
            }
        }
        printf("%d\n",ans.size());
        for (int i=0;i<ans.size();i++)
            printf("%d %d\n",ans[i].fi,ans[i].se);
    }
    return 0;
}
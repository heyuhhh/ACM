#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define out(i,u) for(int i=first[u];i!=-1;i=nxt[i])
using namespace std;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch>'9' || ch<'0') {if(ch=='-')f=-1;ch=getchar();}
    for(;ch>='0' &&ch<='9';ch=getchar()) ret=ret*10+ch-'0';
    return ret*f;
}
const int INF=1<<30;
typedef long long ll;
const int MOD=1e9+7;

const int maxn=200000+10;
const int maxm=400000+10;

int n;
ll val[maxn],y[maxn];
int first[maxn],nxt[maxm],ecnt;
struct Edge{int u,v;Edge(int u=0,int v=0):u(u),v(v){}}e[maxm];
inline void add_edge(int u,int v){
    nxt[ecnt]=first[u];first[u]=ecnt;e[ecnt++]=Edge(u,v);
    nxt[ecnt]=first[v];first[v]=ecnt;e[ecnt++]=Edge(v,u);
}

#define lowbit(x) ((x)&(-(x)))
struct BIT{
    ll C[maxn];
    inline void clear(){rep(i,0,n) C[i]=0;}
    inline void updata(int pos,ll val){
        for(int i=pos;i<=n;i+=lowbit(i)) C[i]=(C[i]+val)%MOD;
    }
    inline ll query(int pos){
        ll ret=0;
        for(int i=pos;i;i-=lowbit(i)) ret+=C[i];
        return ret%MOD;
    }
    inline ll query(int l,int r){if(l>r) return 0; return query(r)-query(l-1);}
}bit[4];
#undef lowbit

int sz[maxn],top[maxn],hv[maxn],fa[maxn],dep[maxn],dfnid[maxn],dfnclk=0;
void dfs1(int u,int pre)
{
	if(u==pre) dep[u]=1;
	else dep[u]=dep[pre]+1;
    fa[u]=pre;
    sz[u]=1;
    out(i,u)
    {
        int v=e[i].v;
        if(v==pre) continue;
        dfs1(v,u);
        sz[u]+=sz[v];
        if(sz[v] > sz[hv[u]]) hv[u]=v;
    }
}

void dfs2(int u,int Top)
{
    top[u]=Top;dfnid[u]=++dfnclk;
    if(sz[u]==1) return ;
    dfs2(hv[u],Top);
    out(i,u) if(e[i].v!=fa[u] && e[i].v!=hv[u]) dfs2(e[i].v,e[i].v);
}

int LCA(int a,int b,int &dis,ll &sumy)
{
    dis=sumy=0;
    for(;top[a]!=top[b];b=fa[top[b]])
    {
        if(dep[top[a]] > dep[top[b]]) swap(a,b);
        dis+=dep[b]-dep[top[b]]+1;
        sumy+=bit[2].query(dfnid[top[b]],dfnid[b]);
    }
    if(dep[a]>dep[b]) swap(a,b);
    dis+=dep[b]-dep[a]+1;
    sumy+=bit[2].query(dfnid[a],dfnid[b]);
    return a;
}

ll sum[maxn],sum2[maxn];

void solve()
{
	cin>>n;
    rep(i,0,3) bit[i].clear();
    rep(i,1,n) first[i]=-1,hv[i]=0;
    ecnt=0;
    dfnclk=0;
    
    rep(i,1,n) val[i]=read();
    rep(i,1,n) y[i]=read();
    rep(i,1,n-1) add_edge(read(),read());
    
    dfs1(1,1);
    dfs2(1,1);

	rep(i,1,n) sum[dfnid[i]]=y[i],sum2[dfnid[i]+1]=y[i];
	rep(i,1,n) sum[i]=(sum[i-1]+sum[i])%MOD,sum2[i]=(sum2[i]+sum2[i-1])%MOD;

    int q;
    cin>>q;
	rep(i,1,n) {
        bit[0].updata(dfnid[i],val[i]);
        bit[1].updata(dfnid[i],val[i]*sum[dfnid[i]]%MOD);
        bit[2].updata(dfnid[i],y[i]);
        bit[3].updata(dfnid[i],val[i]*sum2[dfnid[i]]%MOD);
    }

    int a,b,c;ll x;
    while(q--)
    {
        a=read();
        if(a==1)
        {
            b=read();c=read();x=read();
            int dis=0;
            
            ll sumy=0;
            LCA(b,c,dis,sumy);
            ll ans=0,xb=x,xc=(x-(sumy-y[c]))%MOD;
            ll ans0,ans1;
            for(;top[b]!=top[c];)
            {
                if(dep[top[b]] > dep[top[c]]) //let b up
                {
                    int l=dfnid[top[b]],r=dfnid[b];
                    ans0=bit[0].query(l,r);
                    ans1=bit[1].query(l,r);
                    ans+=(ans1+(xb-sum[r])*ans0)%MOD;
                    b=fa[top[b]];
                    xb=xb-bit[2].query(l,r);
//                    xb=xb-sum[r]+sum[l-1];
                }
                else //let c up
                {
                    int l=dfnid[top[c]],r=dfnid[c];
                    ans0=bit[0].query(l,r);
                    ans1=bit[3].query(l,r);
                    ans+=((xc+sum2[r])*ans0-ans1)%MOD;
                    c=fa[top[c]];
                    xc=xc+bit[2].query(l,r-1);
                    xc+=y[c];
//                    xc=xc+sum[c]-sum[top[c]-1];
                }
            }
            if(dep[b] < dep[c]) //c under b
            {
                int l=dfnid[b],r=dfnid[c];
                ans0=bit[0].query(l,r);
                ans1=bit[3].query(l,r);
                ans+=((xb+sum2[l])*ans0-ans1)%MOD;
            }
            else // b under c
            {
                int l=dfnid[c],r=dfnid[b];
                ans0=bit[0].query(l,r);
                ans1=bit[1].query(l,r);
                ans+=(ans1+(xc-sum[l])*ans0)%MOD;
            }
            ans=(ans%MOD+MOD)%MOD;
            printf("%I64d\n",ans);
        }
        else 
        {
            b=read();x=read();
            bit[0].updata(dfnid[b],-val[b]);
            bit[1].updata(dfnid[b],-val[b]*sum[dfnid[b]]%MOD);
            bit[3].updata(dfnid[b],-val[b]*sum2[dfnid[b]]%MOD);
            val[b]=x;
            bit[0].updata(dfnid[b],val[b]);
            bit[1].updata(dfnid[b],val[b]*sum[dfnid[b]]%MOD);
            bit[3].updata(dfnid[b],val[b]*sum2[dfnid[b]]%MOD);
        }
    }
}

int main()
{
	int T;cin>>T;
	while(T--) solve();
	return 0;
}

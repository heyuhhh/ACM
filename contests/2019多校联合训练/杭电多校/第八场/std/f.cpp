#include<bits/stdc++.h>
#define maxn 202000
#define x first
#define y second

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
const ll inf=1e16;
ll a[maxn],n,k,query,ans,p[maxn],q[maxn],d[maxn];
vector <int> h[maxn];
pi f[maxn],g[maxn];

void dfs(int fa,int u)
{
    for (int i=0;i<h[u].size();i++)
    {
        int v=h[u][i];
        if (v==fa) continue;
        dfs(u,v),d[u]++;
        if (f[u].x<a[u]+g[v].x) f[u].y=f[u].x,f[u].x=a[u]+g[v].x;
        else if (f[u].y<a[u]+g[v].x) f[u].y=a[u]+g[v].x;
        if (g[u].x>a[u]+f[v].x) g[u].y=g[u].x,g[u].x=a[u]+f[v].x;
        else if (g[u].y>a[u]+f[v].x) g[u].y=a[u]+f[v].x;
    }
    if (!d[u]) f[u].x=f[u].y=g[u].x=g[u].y=a[u];
}

void dfs2(int fa,int u)
{
    for (int i=0;i<h[u].size();i++)
    {
        int v=h[u][i]; ll r;
        if (v==fa) continue;
        if (d[u]==1) p[v]=q[u]+a[v],q[v]=p[u]+a[v];
        else {
            r=(f[u].x==g[v].x+a[u])?f[u].y:f[u].x;
            if (u!=1) r=max(r,q[u]); p[v]=r+a[v];
            r=(g[u].x==f[v].x+a[u])?g[u].y:g[u].x;
            if (u!=1) r=min(r,p[u]); q[v]=r+a[v];
        }
        dfs2(u,v);
    }
}

int main()
{
    //freopen("test1.in","r",stdin);
    //freopen("test2.out","w",stdout);
    scanf("%lld",&query);
    while (query--){
        scanf("%lld",&n);
        //printf("%d\n", n);
        for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
        for (int i=1;i<=n;i++) {scanf("%lld",&k); a[i]-=k;}
        for (int i=1;i<=n;i++) h[i].clear(),d[i]=0,f[i].x=f[i].y=-inf,g[i].x=g[i].y=inf;
        for (int i=1;i<n;i++)
        {
            int u,v; scanf("%d%d",&u,&v);
            h[u].push_back(v);
            h[v].push_back(u);
        }
        dfs(0,1); p[1]=q[1]=a[1]; dfs2(0,1); ans=g[1].x;
        //for (int i=1;i<=n;i++) cout << p[i] << ' ' << q[i] << endl;
        //for (int i=1;i<=n;i++) cout << f[i].x << ' ' << f[i].y << ' ' << g[i].x << ' ' << g[i].y << endl;
        for (int i=2;i<=n;i++) if (d[i]) ans=max(ans,min(g[i].x,p[i])); else ans=max(ans,p[i]);
        cout << ans << endl;
    }
    return 0;
}

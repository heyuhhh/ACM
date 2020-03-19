#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5 ;
int n,m,pos,tot;
ll a[N];
struct Edge{
    int u,v;
    ll w;
    bool operator < (const Edge &A)const{
        return w<A.w;
    }
}e[N<<2];
int f[N];
int find(int x){
    return f[x]==x ? f[x] : f[x]=find(f[x]);
}
int main(){
    scanf("%d%d",&n,&m);
    ll mx = 1e18;
    for(int i=1;i<=n;i++){
        scanf("%I64d",&a[i]);
        if(a[i]<mx){
            mx=a[i];
            pos=i;
        }
    }
    for(int i=1;i<=m;i++){
        int u,v;ll w;
        scanf("%d%d%I64d",&u,&v,&w);
        e[++tot].u=u;e[tot].v=v;e[tot].w=w;
    }
    for(int i=1;i<=n;i++){
        if(i==pos) continue ;
        e[++tot].u=i;e[tot].v=pos;
        e[tot].w=a[i]+a[pos];
    }
    for(int i=0;i<=n+1;i++) f[i]=i;
    sort(e+1,e+tot+1);
    ll ans = 0;
    for(int i=1;i<=tot;i++){
        int u=e[i].u,v=e[i].v;
        ll w = e[i].w;
        int fx=find(u),fy=find(v);
        if(fx==fy) continue ;
        else{
            f[fx]=fy;
            ans+=e[i].w;
        }
    }
    cout<<ans<<endl;
    return 0;
}

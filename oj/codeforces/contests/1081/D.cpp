#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N =1e5+5;
struct Edge{
    int u,v,w;
    bool operator < (const Edge&A)const{
        return w<A.w;
    }
}e[N];
int n,m,k;
int a[N],f[N],val[N];
int find(int x){
    if(x==f[x]) return f[x];
    f[x]=find(f[x]);
    return f[x];
}
int main(){
    cin>>n>>m>>k;
    int tot=k;
    for(int i=1,t;i<=k;i++){
        cin>>t;
        a[t]=1;
    }
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        e[i]=Edge{u,v,w};
    }
    for(int i=1;i<=n;i++) f[i]=i;
    sort(e+1,e+m+1);
    int ans;
    for(int i=1;i<=m;i++){
        int u=e[i].u,v=e[i].v,w=e[i].w;
        int fx=find(u),fy=find(v);
        if(fx==fy) continue;
        f[fx]=fy;
        if(a[u]) val[fx]++;if(a[v]) val[fy]++;
        if(val[fx]&&val[fy]) ans=w;
        val[fy]+=val[fx];
    }
    for(int i=1;i<=k;i++) cout<<ans<<" ";
    return 0;
}


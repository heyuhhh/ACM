#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int n,m;
struct Edge{
    int u,v,w;
    bool operator < (const Edge &A)const{
        return w<A.w;
    }
}e[N];
int f[N],d[N],vis[N];
int find(int x){
    return f[x]==x?f[x]:f[x]=find(f[x]);
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    int mx=0,p;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        e[i].u=u;e[i].v=v;
        d[u]++;d[v]++;
        if(d[u]>mx){
            mx=d[u];
            p=u;
        }
        if(d[v]>mx){
            mx=d[v];
            p=v;
        }
    }
    for(int i=0;i<=n+1;i++) f[i]=i;
    for(int i=1;i<=m;i++){
        int u=e[i].u,v=e[i].v;
        if(u==p||v==p){
            int fx=find(u),fy=find(v);
            f[fx]=fy;vis[i]=1;
        }
    }
    for(int i=1;i<=m;i++){
        int fx=find(e[i].u),fy=find(e[i].v);
        if(fx==fy) continue ;
        f[fx]=fy;vis[i]=1;
    }
    for(int i=1;i<=m;i++) if(vis[i]) cout<<e[i].u<<" "<<e[i].v<<'\n';
    return 0;
}

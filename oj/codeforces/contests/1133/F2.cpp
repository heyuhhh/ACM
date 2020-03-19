#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int n,m,k;
struct Edge{
    int u,v;
}e[N];
int f[N],vis[N];
int find(int x){
    return f[x]==x?f[x]:f[x]=find(f[x]);
}
void init(){
    for(int i=0;i<=n;i++) f[i]=i;
}

int main(){
    //ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m>>k;
    init();
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        e[i].u=u;e[i].v=v;
        if(u==1 || v==1) continue ;
        int fx=find(u),fy=find(v);
        if(fx==fy) continue ;
        f[fx]=fy;
    }
    int need = 0;
    for(int i=1;i<=m;i++){
        int u=e[i].u,v=e[i].v;
        if(u==1 ||v==1){
            int fx=find(u),fy=find(v);
            if(fx!=fy){
                f[fx]=fy;
                need++;
                vis[i]=2;
            }else{
                vis[i]=1;
            }
        }
    }
    if(need>k) return puts("NO"),0;
    k-=need;
    init();
    for(int i=1;i<=m;i++){
        if(vis[i]!=2) continue ;
        int u=e[i].u,v=e[i].v;
        int fx=find(u),fy=find(v);
        f[fx]=fy;
    }
    for(int i=1;i<=m;i++){
        if(k==0) break ;
        if(vis[i]==1){
            k--;
            int u=e[i].u,v=e[i].v;
            int fx=find(u),fy=find(v);
            f[fx]=fy;
            vis[i]=3;
        }
    }
    if(k>0) return puts("NO"),0;
    puts("YES");
    for(int i=1;i<=m;i++){
        if(e[i].u==1 || e[i].v==1) continue ;
        int fx=find(e[i].u),fy=find(e[i].v);
        if(fx!=fy){
            f[fx]=fy;
            vis[i]=3;
        }
    }
    for(int i=1;i<=m;i++){
        if(vis[i]>=2) cout<<e[i].u<<" "<<e[i].v<<'\n';
    }
    return 0;
}

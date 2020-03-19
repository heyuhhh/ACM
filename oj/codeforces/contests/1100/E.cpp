#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int n,m,tot;
int head[N],in[N],bfn[N],tmp[N];
struct Edge{
    int u,v,w,id;
    bool operator < (const Edge&A)const{
        return w<A.w;
    }
}edge[N];
struct EDGE{
    int u,v,next;
}e[N];
void adde(int u,int v){
    e[++tot].v=v;e[tot].u=u;e[tot].next=head[u];head[u]=tot;
}
bool check(int x){
    memset(head,-1,sizeof(head));tot=0;
    memset(in,0,sizeof(in));memset(bfn,0,sizeof(tmp));
    for(int i=1;i<=m;i++){
        if(edge[i].w>x){
            adde(edge[i].u,edge[i].v);
            in[edge[i].v]++;
        }
    }
    queue <int> q;
    int cnt = 0;
    for(int i=1;i<=n;i++) if(!in[i]) q.push(i),bfn[i]=++cnt;
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=head[u];i!=-1;i=e[i].next){
            int v=e[i].v;
            in[v]--;
            if(!in[v]) q.push(v),bfn[v]=++cnt;
        }
    }
    if(cnt<n) return false;
    return true;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        edge[i]={u,v,w,i};
    }
    sort(edge+1,edge+1+m);
    int l = 0 , r = 1e9+1,mid;
    int ans=1;
    while(l<r){
        mid=(l+r)>>1;
        if(check(mid)){
            r=mid;
            ans=mid;
        }else l=mid+1;
    }
    check(ans);
    tot=0;
    printf("%d",ans);
    for(int i=1;i<=m;i++){
        int u=edge[i].u,v=edge[i].v,w=edge[i].w;
        if(bfn[u]>bfn[v] && w<=ans){
            tmp[i]=1;
            tot++;
        }
    }
    printf(" %d\n",tot);
    for(int i=1;i<=m;i++){
        if(tmp[i]) printf("%d ",edge[i].id);
    }
    return 0;
}


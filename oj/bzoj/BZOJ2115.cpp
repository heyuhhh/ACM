#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100005,M = 100005;
int n,m,tot,num;
int head[N],vis[N];
ll x[N],cir[N<<1];
struct Edge{
    int u,v,next;
    ll w;
}e[M<<1];
void adde(int u,int v,ll w){
    e[tot].v=v;e[tot].next=head[u];e[tot].w=w;head[u]=tot++;
}
void dfs(int u,int fa){
    vis[u]=1;
    for(int i=head[u];i!=-1;i=e[i].next){
        int v=e[i].v;
        if(v==fa) continue ;
        if(!vis[v]){
            x[v]=x[u]^e[i].w;
            dfs(v,u);
        }else{
            cir[++num]=x[v]^x[u]^e[i].w;
        }
    }
}
ll p[65];
ll ans;
void xor_base(){
    for(int i=1;i<=num;i++){
        for(ll j=62;j>=0;j--){
            if((1LL<<j)&cir[i]){
                if(!p[j]){
                    p[j]=cir[i];
                    break;
                }
                cir[i]^=p[j];
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    memset(head,-1,sizeof(head));tot=num=0;
    for(int i=1;i<=m;i++){
        int u,v;ll w;
        cin>>u>>v>>w;
        adde(u,v,w);adde(v,u,w);
    }
    dfs(1,-1);
    ans=x[n];
    xor_base();
    for(int i=62;i>=0;i--){
        ans=max(ans,ans^p[i]);
    }
    cout<<ans;
    return 0;
}

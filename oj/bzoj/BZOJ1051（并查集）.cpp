#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
using namespace std;

const int N = 10005,M = 50005 ;
int n,m,tot;
int head[N],f[N],sum[N],vis[N];
map<int,map<int,int> > mp;
struct Edge{
    int u,v,next ;
}e[M];
void adde(int u,int v){
    e[++tot].u=u;e[tot].v=v;
    e[tot].next=head[u];
    head[u]=tot;
}
int find(int x){
    return f[x]==x ? f[x] : f[x]=find(f[x]);
}
int main(){
    cin>>n>>m;
    int st=0;
    memset(head,-1,sizeof(head));
    for(int i=1;i<=N-5;i++) f[i]=i,sum[i]=1;
    for(int i=1,u,v;i<=m;i++){
        scanf("%d%d",&u,&v);
        if(!mp[u][v]){
            mp[u][v]=1;
            adde(u,v);
            int fx=find(u),fy=find(v);
            if(fx!=fy){
                f[fx]=fy;
                sum[fy]+=sum[fx];
                if(sum[fy]==n) st=fy;
            }
        }
    }
    int cnt =1;
    if(!st)puts("0");
    else{
        queue<int> q;
        q.push(st);vis[st]=1;
        while(!q.empty()){
            int u=q.front();q.pop();
            for(int i=head[u];i!=-1;i=e[i].next){
                int v=e[i].v;
                if(!vis[v]){
                    vis[v]=1;
                    q.push(v);
                    cnt++;
                }
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}



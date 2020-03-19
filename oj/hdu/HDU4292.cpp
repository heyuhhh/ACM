#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#define t 1000
#define INF 99999999
using namespace std;
typedef long long ll;
const int N = 1005;
int n,F,D,tot;
int head[N],d[N];
struct Edge{
    int v,next,c;
}e[(N*N)<<1];
void adde(int u,int v,int c){
    e[tot].v=v;e[tot].c=c;e[tot].next=head[u];head[u]=tot++;
    e[tot].v=u;e[tot].c=0;e[tot].next=head[v];head[v]=tot++;
}
bool bfs(int S,int T){
    memset(d,0,sizeof(d));d[S]=1;
    queue <int > q;q.push(S);
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=head[u];i!=-1;i=e[i].next){
            int v=e[i].v;
            if(!d[v] && e[i].c>0){
                d[v]=d[u]+1;
                q.push(v);
            }
        }
    }
    return d[t]!=0;
}
int dfs(int s,int a){
    int flow=0,f;
    if(s==t || a==0) return a;
    for(int i=head[s];i!=-1;i=e[i].next){
        int v=e[i].v;
        if(d[v]!=d[s]+1) continue ;
        f=dfs(v,min(a,e[i].c));
        if(f){
            e[i].c-=f;
            e[i^1].c+=f;
            flow+=f;
            a-=f;
            if(a==0) break;
        }
    }
    if(!flow) d[s]=-1;
    return flow;
}
int Dinic(){
    int max_flow=0;
    while(bfs(0,t))
        max_flow+=dfs(0,INF);
    return max_flow;
}
int main(){
    while(~scanf("%d%d%d",&n,&F,&D)){
        tot=0;memset(head,-1,sizeof(head));
        for(int i=1,c;i<=F;i++){
            scanf("%d",&c);
            adde(0,i,c);
        }
        for(int i=1,c;i<=D;i++){
            scanf("%d",&c);
            adde(600+i,t,c);
        }
        for(int i=201;i<=400;i++) adde(i,i+200,1);
        char s[300];
        for(int i=1;i<=n;i++){
            scanf("%s",s);
            for(int j=0;j<F;j++){
                if(s[j]=='Y') adde(j+1,i+200,1);
            }
        }
        for(int i=1;i<=n;i++){
            scanf("%s",s);
            for(int j=0;j<D;j++){
                if(s[j]=='Y') adde(400+i,600+j+1,1);
            }
        }
        printf("%d\n",Dinic());
    }
    return 0;
}


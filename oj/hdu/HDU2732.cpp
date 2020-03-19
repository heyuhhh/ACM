#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <cmath>
#define INF 99999999
#define t 1000
using namespace std;

const int N = 30;
int T,Case,tot,D,n,m;
int head[1005],d[1005],cur[1005];
int map[N][N];

struct Edge{
    int v,next,c;
}e[500000];
void adde(int u,int v,int c){
    e[tot].v=v;e[tot].c=c;e[tot].next=head[u];head[u]=tot++;
    e[tot].v=u;e[tot].c=0;e[tot].next=head[v];head[v]=tot++;
}
int dis(int x1,int y1,int x2,int y2){
    return abs(x1-x2)+abs(y1-y2);
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
    return d[T]!=0;
}
int dfs(int s,int a){
    int flow=0,f;
    if(s==t || a==0) return a;
    for(int &i=cur[s];i!=-1;i=e[i].next){
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
    while(bfs(0,t)){
        for(int i=0;i<=t;i++) cur[i]=head[i];
        max_flow+=dfs(0,INF);
    }
    return max_flow;
}
int main(){
    scanf("%d",&T);
    while(T--){
        Case++;
        tot=0;memset(head,-1,sizeof(head));
        scanf("%d%d",&n,&D);
        char s[N];
        for(int i=1;i<=n;i++){
            scanf("%s",s);
            m = strlen(s);
            for(int j=0;j<m;j++){
                if(s[j]==0) continue ;
                map[i][j+1]=s[j]-'0';
                if(i<=D || n-i+1<=D || j+1<=D || m-j<=D){
                    int u = (i-1)*m+j+1;
                    adde(u+400,t,map[i][j+1]);
                }
            }
        }
        int sum = 0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(map[i][j]) adde((i-1)*m+j,(i-1)*m+j+400,map[i][j]);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(map[i][j]){
                    for(int _i=max(1,i-3);_i<=min(n,i+3);_i++){
                        for(int _j=max(1,j-3);_j<=min(m,j+3);_j++){
                            if(!map[_i][_j] || (i==_i && j==_j)) continue ;
                            if(dis(i,j,_i,_j)<=D)
                                adde((i-1)*m+j+400,(_i-1)*m+_j,INF);
                        }
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            scanf("%s",s);
            for(int j=1;j<=m;j++)
            if(s[j-1]=='L') adde(0,(i-1)*m+j,1),sum++;
        }
        int cnt=Dinic();
        int left = sum-cnt;
        if(!left) printf("Case #%d: no lizard was left behind.\n",Case);
        else if(left==1) printf("Case #%d: 1 lizard was left behind.\n",Case);
        else printf("Case #%d: %d lizards were left behind.\n",Case,left);
    }
    return 0;
}


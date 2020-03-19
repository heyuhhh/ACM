#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#define INF 99999999
#define t 500
using namespace std;

const int N = 505;
int head[N],d[N];
int tot,n,m,k,cnt;
struct Edge{
    int v,next,c;
}e[N<<1];
char str[N][30],s[30],tmp[30];
void adde(int u,int v,int c){
    e[tot].v=v;e[tot].next=head[u];e[tot].c=c;head[u]=tot++;
    e[tot].v=u;e[tot].next=head[v];e[tot].c=0;head[v]=tot++;
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
    int max_flow = 0;
    while(bfs(0,t)){
        max_flow+=dfs(0,INF);
    }
    return max_flow;
}
int num=0;
int Search(char *s){
    if(num==0){
        strcpy(str[1],s);
        num++;
        return 1;
    }
    for(int i=1;i<=num;i++){
        if(strcmp(str[i],s)==0) return i;
    }
    num++;
    strcpy(str[num],s);
    return num;
}
int main(){
    scanf("%d",&n);
    memset(head,-1,sizeof(head));
    for(int i=1;i<=n;i++){
        scanf("%s",s);
        int a=Search(s);
        adde(0,a,1);
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        scanf("%s%s",tmp,s);
        int a=Search(s);
        adde(a,t,1);
    }
    scanf("%d",&k);
    for(int i=1;i<=k;i++){
        scanf("%s%s",tmp,s);
        int a=Search(tmp),b=Search(s);
        adde(b,a,INF);
    }
    printf("%d",m-Dinic());
    return 0;
}


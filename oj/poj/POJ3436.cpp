#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define INF 99999999
using namespace std;

const int N = 150;
int P,n,tot;
int p[N],m[N][N],head[N],cur[N],d[N];

struct Edge{
    int u,v,c,flow,next;
}e[N<<1];
void adde(int u,int v,int w,int f){
    e[tot].v=v;e[tot].u=u;e[tot].c=w;e[tot].flow=f;
    e[tot].next=head[u];head[u]=tot++;
}
bool bfs(int s,int t){
    for(int i=0;i<=2*n+2;i++) d[i]=0;d[s]=1;
    queue <int > q;q.push(s);
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=head[u];i!=-1;i=e[i].next){
            int v=e[i].v;
            if(!d[v] && e[i].c>e[i].flow){
                d[v]=d[u]+1;
                q.push(v);
            }
        }
    }
    return d[t]!=0;
}
int dfs(int s,int a){
    if(s==2*n+1 || a==0) return a;
    int flow = 0;
    for(int &i=cur[s];i!=-1;i=e[i].next){
        int v=e[i].v,f;
        if(d[v]!=d[s]+1) continue ;
        f=dfs(v,min(a,e[i].c-e[i].flow));
        if(f){
            e[i].flow+=f;
            e[i^1].flow-=f;
            a-=f;
            flow+=f;
            if(a==0) break;
        }
    }
    if(!flow) d[s]=-1;
    return flow;
}
int main(){
    scanf("%d%d",&P,&n);
    memset(head,-1,sizeof(head));
    for(int i=1;i<=n;i++){
        scanf("%d",&p[i]);
        for(int j=1;j<=2*P;j++) scanf("%d",&m[i][j]);
    }

    for(int i=1;i<=n;i++){
        adde(i,i+n,p[i],0);
        adde(i+n,i,0,0);
        int flag1=1,flag2=1;
        for(int j=1;j<=P;j++){
            if(m[i][j]==1) flag1=0;
            if(m[i][j+P]!=1) flag2=0;
        }
        if(flag1) adde(0,i,INF,0),adde(i,0,0,0);
        if(flag2) adde(i+n,2*n+1,INF,0),adde(2*n+1,i+n,0,0);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) continue ;
            bool ok = true ;
            for(int k=P+1;k<=P*2;k++){
                int now = k-P;
                if(m[j][now]==2) continue ;
                if(m[i][k]!=m[j][now]) ok=false;
            }
            if(ok){
                adde(i+n,j,INF,0);
                adde(j,i+n,0,0);
            }
        }
    }

    int max_flow = 0;
    while(bfs(0,2*n+1)){
        for(int i=0;i<=2*n+1;i++) cur[i]=head[i];
        max_flow+=dfs(0,INF);
    }
    printf("%d ",max_flow);
    int tot=0;
    vector <pair<int,int> > ans[N];
    for(int i=1+n;i<=2*n;i++){
        for(int j=head[i];j!=-1;j=e[j].next){
            int v=e[j].v;
            if(v!=2*n+1 && v!=0 && e[j].flow && v!=i-n) ans[i-n].push_back(make_pair(v,e[j].flow)),tot++;
        }
    }
    printf("%d\n",tot);
    for(int i=1;i<=n;i++)
        for(int j=0;j<ans[i].size();j++){
            printf("%d %d %d\n",i,ans[i][j].first,ans[i][j].second);
        }
    return 0;
}


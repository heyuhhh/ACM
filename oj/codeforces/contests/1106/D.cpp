#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
int n,m;
struct Edge{
    int u,v,next;
}e[N<<1];
int tot;
int head[N],vis[N];
void adde(int u,int v){
    e[tot].v=v;e[tot].next=head[u];head[u]=tot++;
}
priority_queue <int,vector<int>,greater<int> > q;
queue <int> que;
void dfs(int s){
    que.push(s);
    vis[s]=1;
    for(int i=head[s];i!=-1;i=e[i].next){
        int v=e[i].v;
        q.push(v);
    }
    while(!q.empty() && vis[q.top()]) q.pop();
    if(q.empty()) return ;
    int v=q.top();q.pop();
    dfs(v);
}
int main(){
    scanf("%d%d",&n,&m);
    memset(head,-1,sizeof(head));
    for(int i=1;i<=m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        if(u==v) continue ;
        adde(u,v);adde(v,u);
    }
    dfs(1);
    while(!que.empty()){
        int now=que.front();
        printf("%d ",now);
        que.pop();
    }
    return 0;
}

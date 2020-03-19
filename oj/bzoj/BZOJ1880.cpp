/**************************************************************
    Problem: 1880
    User: heyuhhh
    Language: C++
    Result: Accepted
    Time:1052 ms
    Memory:63952 kb
****************************************************************/
 
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int M = 4000005,N = 1505 ;
int n,m;
int s1,s2,t1,t2;
struct Edge{
    int u,v,w,next ;
}e[M];
int tot;
int head[N],d[4][N],vis[N];
struct node{
    int u;
    ll d;
    bool operator < (const node &A)const{
        return d>A.d;
    }
};
void adde(int u,int v,int w){
    e[tot].v=v;e[tot].w=w;e[tot].next=head[u];head[u]=tot++;
}
void Dijkstra(int s,int id){
    priority_queue <node> q;memset(d[id],INF,sizeof(d[id]));
    memset(vis,0,sizeof(vis));d[id][s]=0;
    q.push(node{s,0});
    while(!q.empty()){
        node cur = q.top();q.pop();
        int u=cur.u;
        if(vis[u]) continue ;
        vis[u]=1;
        for(int i=head[u];i!=-1;i=e[i].next){
            int v=e[i].v;
            if(d[id][v]>d[id][u]+(ll)e[i].w){
                d[id][v]=d[id][u]+(ll)e[i].w;
                q.push(node{v,d[id][v]});
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    cin>>s1>>t1>>s2>>t2;
    memset(head,-1,sizeof(head));
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adde(u,v,w);adde(v,u,w);
    }
    Dijkstra(s1,0);Dijkstra(t1,1);
    Dijkstra(s2,2);Dijkstra(t2,3);
    int mn1=d[0][t1],mn2=d[2][t2];
    //cout<<mn1<<" "<<mn2<<endl;
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) continue ;
            int need = mn1-d[0][i]-d[1][j];
            if(mn2-d[2][i]-d[3][j]==need||mn2-d[2][j]-d[3][i]==need){
                ans=max(ans,need);
            }
        }
    }
    cout<<ans;
    return 0;
}

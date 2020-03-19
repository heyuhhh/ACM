#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <map>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int N = 805;
int x,y,X,Y,cnt,num,s,t;
map <ll,map<ll,int> > p;
double d[N];
int vis[N],head[N];
struct node{
    int x,y;
};
vector <node> vec[N];
double dis(int X1,int X2,int Y1,int Y2){
    return sqrt((double)(X1-X2)*(X1-X2)+(double)(Y1-Y2)*(Y1-Y2));
}
double T(double d,int op){
    if(op==1) return 6*d/1000.0;
    else return 6*d/4000.0;
}
struct Edge{
    int u,v,next ;
    double w;
}e[N*N<<2];
int tot;
struct Node{
    double d;
    int u;
    bool operator < (const Node &A)const{
        return d>A.d;
    }
};
void adde(int u,int v,double w){
    e[tot].v=v;e[tot].w=w;e[tot].next=head[u];head[u]=tot++;
}
void Dijkstra(int s){
    priority_queue <Node> q;
    for(int i=0;i<=t;i++) d[i]=INF;
    memset(vis,0,sizeof(vis));d[s]=0;
    Node now;
    now.d=0;now.u=s;
    q.push(now);
    while(!q.empty()){
        Node cur = q.top();q.pop();
        int u=cur.u;
        if(vis[u]) continue ;
        vis[u]=1;
        for(int i=head[u];i!=-1;i=e[i].next){
            int v=e[i].v;
            if(d[v]>d[u]+e[i].w){
                d[v]=d[u]+e[i].w;
                now.d=d[v];now.u=v;
                q.push(now);
            }
        }
    }
}
int main(){
    cin>>x>>y>>X>>Y;
    int xx,yy;
    memset(head,-1,sizeof(head));
    while(scanf("%d",&xx)!=EOF){
        scanf("%d",&yy);
        cnt++;
        node cur;
        cur.x=xx;cur.y=yy;
        vec[cnt].push_back(cur);
        while(1){
            scanf("%d%d",&xx,&yy);
            if(xx==-1 && yy==-1) break ;
            cur.x=xx;cur.y=yy;
            vec[cnt].push_back(cur);
        }
    }
    s=0;t=300;
    for(int i=1;i<=cnt;i++){
        for(int j=0;j<vec[i].size();j++){
            node cur = vec[i][j];
            if(p[cur.x][cur.y]==0) p[cur.x][cur.y]=++num;
            adde(s,p[cur.x][cur.y],T(dis(0,cur.x,0,cur.y),1));
            adde(p[cur.x][cur.y],t,T(dis(cur.x,X,cur.y,Y),1));
        }
    }
    adde(s,t,T(dis(x,X,y,Y),1));
    for(int i1=1;i1<=cnt;i1++){
        for(int j1=0;j1<vec[i1].size();j1++){
            int len1 = vec[i1].size();
            node cur1 = vec[i1][j1];
            if(j1>0){
                node cur2 = vec[i1][j1-1];
                adde(p[cur1.x][cur1.y],p[cur2.x][cur2.y],T(dis(cur1.x,cur2.x,cur1.y,cur2.y),2));
            }
            if(j1<len1-1){
                node cur2 = vec[i1][j1+1];
                adde(p[cur1.x][cur1.y],p[cur2.x][cur2.y],T(dis(cur1.x,cur2.x,cur1.y,cur2.y),2));
            }
            for(int i2=1;i2<=cnt;i2++){
                for(int j2=0;j2<vec[i2].size();j2++){
                    node cur2 = vec[i2][j2];
                    adde(p[cur1.x][cur1.y],p[cur2.x][cur2.y],T(dis(cur1.x,cur2.x,cur1.y,cur2.y),1));
                }
            }
        }
    }
    Dijkstra(s);
    cout<<(int)(d[t]+0.5);
    return 0;
}

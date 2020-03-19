#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#define s 0
#define t 200
#define INF 0x3f3f3f3f
#define st n*(n-1)/2
using namespace std;
typedef long long ll;
const int N = 1005;
int T;
char str[N];
int a[N],vis[N],head[N],d[N];
int ans,tot,mx,n,sum;
struct Edge{
    int v,c,next;
}e[N*N];
void adde(int u,int v,int c){
    e[tot].v=v;e[tot].next=head[u];e[tot].c=c;head[u]=tot++;
    e[tot].v=u;e[tot].next=head[v];e[tot].c=0;head[v]=tot++;
}
void build(){
    memset(head,-1,sizeof(head));tot=0;
    for(int i=1;i<=st;i++) adde(s,i,1);
    int fir = st+1,last = st+2;
    for(int i=1;i<=st;i++){
        if(vis[fir]&&a[last-st]>a[fir-st]){
            adde(i,fir,1);adde(i,last,0);
        }else if(vis[last]&&a[last-st]<a[fir-st]){
            adde(i,fir,0);adde(i,last,1);
        }else{
            adde(i,fir,1);adde(i,last,1);
        }
        last++;
        if(last>st+n){
            fir++;last=fir+1;
        }
    }
    for(int i=st+1;i<=st+n;i++) adde(i,t,a[i-st]);
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
int dfs(int S,int a){
    int flow=0,f;
    if(S==t || a==0) return a;
    for(int i=head[S];i!=-1;i=e[i].next){
        int v=e[i].v;
        if(d[v]!=d[S]+1) continue ;
        f=dfs(v,min(a,e[i].c));
        if(f){
            e[i].c-=f;
            e[i^1].c+=f;
            flow+=f;
            a-=f;
            if(a==0) break;
        }
    }
    if(!flow) d[S]=-1;
    return flow;
}
int Dinic(){
    int max_flow=0;
    while(bfs(0,t)) max_flow+=dfs(0,INF);
    return max_flow;
}
int main(){
    cin>>T;
    getchar();
    while(T--){
        memset(vis,0,sizeof(vis));
        gets(str);
        mx=n=sum=0;ans=-1;
        int len = strlen(str);
        for(int i=0;i<len;i++)
            if(str[i]<='9' && str[i]>='0')
                a[++n]=str[i]-'0',mx = max(mx,a[n]),sum+=a[n];
        for(int i=n;i>=1;i--){
            if(a[i]==mx) continue ;
            vis[i+st]=1;
            build();
            int max_flow=Dinic();
            if(max_flow<sum){
                ans=n-i;
                break ;
            }
        }
        if(ans==-1) ans=n;
        cout<<ans<<endl;  
    }
    return 0;
}


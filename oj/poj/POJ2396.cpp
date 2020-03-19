#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#define s 0
#define t 300
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int N = 205,M = 25,MAXN = 305;
int T;
int n,m,tot;
int mx[N][M],mn[N][M],head[MAXN],r[N],c[M],ans[N][M],d[MAXN];
struct Edge{
    int v,next,c;
}e[(MAXN*MAXN)<<1];
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
    //freopen("2.txt","w",stdout);
    cin>>T;
    while(T--){
        int ok=1;
        scanf("%d%d",&n,&m);
        memset(mn,0,sizeof(mn));
        memset(mx,INF,sizeof(mx));
        memset(ans,0,sizeof(ans));
        for(int i=1;i<=n;i++) scanf("%d",&r[i]);
        for(int i=1;i<=m;i++) scanf("%d",&c[i]);
        int tt;
        scanf("%d",&tt);
        while(tt--){
            int u,v,w;char C;
            scanf("%d %d %c %d",&u,&v,&C,&w);
            if(C=='='){
                if(u==0 && v){
                    for(int i=1;i<=n;i++){
                        if(ans[i][v]){
                            if(ans[i][v]!=w) ok=0;
                            continue ;
                        }
                        ans[i][v]=w;
                        r[i]-=w;
                        c[v]-=w;
                    }
                }else if(v==0 && u){
                    for(int i=1;i<=m;i++){
                        if(ans[u][i]){
                            if(ans[u][i]!=w) ok=0;
                            continue ;
                        }
                        ans[u][i]=w;
                        c[i]-=w;
                        r[u]-=w;
                    }
                }else if(!v && !u){
                    int tmp = 0;
                    for(int i=1;i<=n;i++){
                        for(int j=1;j<=m;j++){
                            if(ans[i][j]){
                                if(ans[i][j]!=w) ok=0;
                                continue ;
                            }
                            ans[i][j]=w;
                            r[i]-=w;c[j]-=w;
                        }
                    }
                }else{
                    if(ans[u][v]){
                        if(ans[u][v]!=w) ok=0;
                        continue ;
                    }
                    r[u]-=w;c[v]-=w;
                    ans[u][v]=w;
                }
            }else if(C=='>'){
                if(u==0 && v){
                    for(int i=1;i<=n;i++) mn[i][v]=max(mn[i][v],w+1);
                }else if(v==0 && u){
                    for(int i=1;i<=m;i++) mn[u][i]=max(mn[u][i],w+1);
                }else if(!v && !u){
                    for(int i=1;i<=n;i++)
                        for(int j=1;j<=m;j++)
                            mn[i][j]=max(mn[i][j],w+1);
                }else mn[u][v]=max(mn[u][v],w+1);
            }else{
                if(u==0 && v){
                    for(int i=1;i<=n;i++) mx[i][v]=min(mx[i][v],w-1);
                }else if(v==0 && u){
                    for(int i=1;i<=m;i++) mx[u][i]=min(mx[u][i],w-1);
                }else if(!v && !u){
                    for(int i=1;i<=n;i++)
                        for(int j=1;j<=m;j++)
                            mx[i][j]=min(mx[i][j],w-1);
                }else mx[u][v]=min(mx[u][v],w-1);
            }
        }
        memset(head,-1,sizeof(head));tot=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(mx[i][j]<mn[i][j])ok=0;
                if(ans[i][j]){
                    if(ans[i][j]<mn[i][j]||ans[i][j]>mx[i][j]) ok=0;
                    continue ;
                }
                r[i]-=mn[i][j];
                c[j]-=mn[i][j];
                adde(i,j+n,mx[i][j]-mn[i][j]);
                if(r[i]<0 || c[j]<0) ok=0;
            }
        }
        int sum1=0,sum2=0;
        for(int i=1;i<=n;i++) sum1+=r[i];
        for(int i=1;i<=m;i++) sum2+=c[i];
        if(sum1!=sum2) ok=0;
        if(!ok){
            puts("IMPOSSIBLE");
            continue ;
        }
        for(int i=1;i<=n;i++) adde(s,i,r[i]);
        for(int i=1;i<=m;i++) adde(n+i,t,c[i]);
        int max_flow=Dinic();
        for(int i=head[s];i!=-1;i=e[i].next){
            if(e[i].c!=0) ok=0;
        }
        if(!ok) puts("IMPOSSIBLE");
        else{
            for(int u=1;u<=n;u++){
                for(int j=head[u];j!=-1;j=e[j].next){
                    if(e[j].v<=n) continue ;
                    int v=e[j].v-n;
                    if(ans[u][v]) continue ;
                    ans[u][v]=ans[u][v]+mx[u][v]-e[j].c;
                }
            }
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
            cout<<endl;
        }
    }
    return 0;
}

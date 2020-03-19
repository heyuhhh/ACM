#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 2005;
int t;
int n,m,tot;
int match[N],head[N],link[N][N],check[N];
stack <int> s;
vector <int> ans;
int T,num;
int scc[N],dfn[N],low[N],vis[N];
struct Edge{
    int u,v,next;
}e[N*N];
void adde(int u,int v){
    e[tot].v=v;e[tot].u=u;e[tot].next=head[u];head[u]=tot++;
}
void Tarjan(int u){
    dfn[u]=low[u]=++T;vis[u]=1;
    s.push(u);
    for(int i=head[u];i!=-1;i=e[i].next){
        int v=e[i].v;
        if(!vis[v]){
            Tarjan(v);
            low[u]=min(low[u],low[v]);
        }else if(!scc[v]){
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(low[u]==dfn[u]){
        num++;int now;
        do{
            now = s.top();s.pop();
            scc[now]=num;
        }while(!s.empty() && now!=u);
    }
}
int dfs(int x,int nown){
    for(int i=1;i<=nown;i++){
        if(!check[i] && link[x][i]){
            check[i]=1;
            if(match[i]==-1 || dfs(match[i],nown)){
                match[i]=x;
                return 1;
            }
        }
    }
    return 0;
}
int hungry(int n1,int m1){
    memset(match,-1,sizeof(match));
    int ans=0;
    for(int i=1;i<=n1;i++){
        memset(check,0,sizeof(check));
        ans+=dfs(i,m1);
    }
    return ans ;
}
void init(){
    memset(link,0,sizeof(link));
    memset(match,-1,sizeof(match));
    memset(head,-1,sizeof(head));
    memset(scc,0,sizeof(scc));
    memset(dfn,0,sizeof(dfn));
    memset(vis,0,sizeof(vis));
    num=0;T=0;tot=0;
}
int main(){
    cin>>t;
    int Case = 0;
    while(t--){
        Case++;
        init();
        scanf("%d%d",&n,&m);
        for(int i=1,k;i<=n;i++){
            scanf("%d",&k);
            for(int j=1,l;j<=k;j++){
                scanf("%d",&l);
                link[i][l]=1;
            }
        }
        int cnt=hungry(n,m);
        int nown,nowm;
        nown=nowm=n+m-cnt;
        for(int i=n+1;i<=nown;i++){
            for(int j=1;j<=nown;j++){
                link[i][j]=1;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=m+1;j<=nowm;j++){
                link[i][j]=1;
            }
        }
        hungry(nown,nowm);
        for(int i=1;i<=nown;i++){
            for(int j=1;j<=nowm;j++){
                if(link[i][j]) adde(i,nown+j);
            }
        }
        for(int i=1;i<=nown;i++){
            if(match[i]!=-1) adde(i+nown,match[i]);
        }
        printf("Case #%d:\n",Case);
        while(!s.empty()) s.pop();
        for(int i=1;i<=2*nown;i++){
            if(!vis[i]) Tarjan(i);
        }
        for(int i=1;i<=n;i++){
            ans.clear();
            for(int j=head[i];j!=-1;j=e[j].next){
                int v=e[j].v;v-=nown;
                if(v>m) continue ;
                if(scc[i]==scc[v+nown]) ans.push_back(v);
            }
            sort(ans.begin(),ans.end());
            printf("%d",(int)ans.size());
            for(int j=0;j<ans.size();j++){
                printf(" %d",ans[j]);
            }
            printf("\n");
        }
    }
    return 0;
}¡¢ 

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1005;
int n,m,scc,best;
vector <int> g[N];
int in[N],mx[N],len[N],pre[N],center[N];
void dfs1(int u,int belong){
    in[u]=belong;
    for(auto v :g[u])
        if(!in[v]) dfs1(v,belong);
}
int maxn;
int dfs(int u,int pa,int d){
    int node=0;
    pre[u]=pa;
    if(d>=maxn){
        maxn=d;
        node = u;
    }
    for(auto v:g[u]){
        int f;
        if(v!=pa){
            f=dfs(v,u,d+1);
            if(f>0) node = f;
        }
    }
    return node;
}
void find_max(int num){
    int s,d=0;
    for(int i=1;i<=n;i++)
        if(in[i]==num){
            s=i;break ;
        }
    maxn=0;
    s=dfs(s,-1,d);
    maxn=0;d=0;
    memset(pre,-1,sizeof(pre));
    s=dfs(s,-1,d);
    mx[num]=maxn;
    if(maxn>best) best = maxn ;
    len[num]=(maxn+1)/2;
    int cnt = 0;
    for(int i=s;i!=-1;i=pre[i]){
        cnt++;
        if(cnt-1==len[num]){
            center[num]=i;
            break ;
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);g[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(!in[i]){
            scc++;
            dfs1(i,scc);
            find_max(scc);
        }
    }
    int s;
    for(int i=1;i<=scc;i++){
        if(mx[i]==best){
            s=i;
            break ;
        }
    }
    int ans = best;
    for(int i=1;i<=scc;i++){
        if(i==s) continue ;
        ans= max(len[s]+len[i]+1,ans);
    }
    for(int i=1;i<=scc;i++){
        for(int j=1;j<=scc;j++){
            if(i==s || j==s || i==j) continue ;
            ans=max(ans,len[i]+len[j]+2);
        }
    }
    cout<<ans<<endl;
    for(int i=1;i<=scc;i++){
        if(i==s) continue ;
        cout<<center[i]<<" "<<center[s]<<endl;
    }
    return 0;
}


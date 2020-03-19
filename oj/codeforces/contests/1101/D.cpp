#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int a[N],vis[N];
int ans,n;
vector <int> g[N],vec[N];
int dfs(int u){
    vis[u]=0;
    int mx = 0;
    for(int v:g[u]){
        if(vis[v]){
            int now = dfs(v);
            ans = max(ans,now+1+mx);
            mx = max(mx,now);
        }
    }
    ans=max(ans,1);
    return mx+1;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        for(int j=1;j*j<=a[i];j++){
            if(a[i]%j) continue ;
            vec[j].push_back(i);
            if(j*j!=a[i]) vec[a[i]/j].push_back(i);
        }
    }
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=2;i<=2e5;i++){
        for(int v:vec[i]) vis[v]=1;
        for(int u:vec[i]) if(vis[u]) dfs(u);
    }
    printf("%d",ans);
    return 0;
}

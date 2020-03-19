#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5 ;
int n;
int a[N];
ll dp[N];
vector <int> g[N];
ll sum,ans;
void dfs1(int u,int pa,int d){
    sum+=(ll)d*a[u];
    dp[u]=a[u];
    for(auto v:g[u]){
        if(v!=pa){
            dfs1(v,u,d+1);
            dp[u]+=dp[v];
        }
    }
    return ;
}
void go(int u,int pa,ll k){
    ans=max(ans,k);
    for(auto v:g[u]){
        if(v!=pa) go(v,u,k-dp[v]+dp[1]-dp[v]);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);g[v].push_back(u);
    }
    dfs1(1,-1,0);
    go(1,-1,sum);
    cout<<ans<<endl;
    return 0;
}


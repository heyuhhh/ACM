#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int n;
vector <int> g[N];
ll sum[N],b[N];
int flag = 0;
void dfs(int u,ll a,int fa){
    int son = 0;
    if(flag) return ;
    int f=0;
    for(auto v:g[u]){
        if(v==fa) continue ;
        if((sum[u]==-1 && sum[v]>=0) ||f){
            f=1;
            ll now=sum[v]-a;
            if(sum[u]==-1) sum[u]=now+a;
            if(sum[u]!=-1) sum[u]=min(sum[u],now+a);
        }
    }
    for(auto v:g[u]){
        if(v==fa) continue ;
        son++;
        if(sum[v]==-1 && sum[u]==-1){
            dfs(v,a,u);
            continue ;
        }
        dfs(v,sum[u],u);
    }
    if(son==0&&sum[u]==-1){
        b[u]=0;
        return ;
    }
    if(sum[u]!=-1) b[u]=sum[u]-a;
}
int main(){
    cin>>n;
    for(int i=2;i<=n;i++){
        int f;
        scanf("%d",&f);
        g[f].push_back(i);
        g[i].push_back(f);
    }
    for(int i=1;i<=n;i++) scanf("%I64d",&sum[i]);
    if(sum[1]==-1) sum[1]=0;
    dfs(1,0,-1);
    for(int i=1;i<=n;i++){
        if(b[i]<0) flag=1;
    }
    if(flag) puts("-1");
    else{
        ll ans = 0;
        for(int i=1;i<=n;i++) ans+=b[i];
        cout<<ans;
    }
    return 0;
}
/*
7
1
2
1
4 4 5
0 -1 3 -1 -1 3 -1
*/


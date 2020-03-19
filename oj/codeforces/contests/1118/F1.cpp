#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5+5;
int n,sum1,sum2;
int a[N],cnt1[N],cnt2[N];
vector <int> g[N];
int ans;
void dfs(int u,int fa){
    if(a[u]==1) cnt1[u]++;
    if(a[u]==2) cnt2[u]++;
    for(auto v:g[u]){
        if(v==fa) continue ;
        dfs(v,u);
        cnt1[u]+=cnt1[v];
        cnt2[u]+=cnt2[v];
    }
    if(cnt1[u]==sum1 && !cnt2[u]) ans++;
    if(!cnt1[u] && cnt2[u]==sum2) ans++;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        if(a[i]==1) sum1++;
        if(a[i]==2) sum2++;
    }
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,-1);
    cout<<ans;
    return 0;
}

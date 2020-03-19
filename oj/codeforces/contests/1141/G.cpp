#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int n,k;
vector <pair<int,int> > g[N];
int du[N];
int ans[N];
int l,r,mid;
bool check(int x){
    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(du[i]>x) cnt++;
    }
    return cnt<=k;
}
void dfs(int u,int fa,int cnt){
    for(auto to:g[u]){
        int v = to.first,id = to.second;
        if(v==fa) continue ;
        ans[id]=cnt++;;
        if(cnt>r) cnt = 1;
        dfs(v,u,cnt);
    }
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(mp(v,i));
        g[v].push_back(mp(u,i));
        du[u]++;du[v]++;
    }
    l=1,r=N;
    while(l<r){
        mid = (l+r)>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    cout<<r<<'\n';
    dfs(1,-1,1);
    for(int i=1;i<n;i++) cout<<ans[i]<<" ";
    return 0;
}

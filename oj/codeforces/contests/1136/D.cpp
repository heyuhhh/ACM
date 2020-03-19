#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+5;
int n,m;
int a[N],cnt[N],p[N];
vector <int> g[N];
void adde(int u){
    for(auto v:g[u]) cnt[v]++;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i],p[a[i]]=i;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        g[v].push_back(u);
    }
    int ans = 0;
    adde(a[n]);
    for(int i=n-1;i>=1;i--){
        if(cnt[a[i]]==n-i-ans) ans++;
        else adde(a[i]);
    }
    cout<<ans;
    return 0;
}

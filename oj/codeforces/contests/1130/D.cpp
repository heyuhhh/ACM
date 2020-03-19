#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int N = 5005;
int n,m;
vector <int> g[N];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
    }
    for(int i=1;i<=n;i++){
        int ans = 0,tot;
        for(int j=1;j<=n;j++){
            int num = g[j].size();
            if(num==0) continue ;
            tot=INF;
            for(auto v:g[j]){
                tot=min(tot,(num-1)*n+(j-i+n)%n+(v-j+n)%n);
            }
            ans=max(ans,tot);
        }
        cout<<ans<<" ";
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
int n,m;
struct Edge{
    int u,v,next,t;
}e[N];
int head[N];
int tot;
void adde(int u,int v){
    e[tot].t=(tot + 1);e[tot].v=v;e[tot].next=head[u];head[u]=tot++;
}
vector <int> g[N];
int c[N],ans[N],vis[N];
int f;
void dfs(int u,int fa,int col){
    c[u] = col ;
    if(f) return ;
    for(auto v : g[u]) {
        if(c[v]==0) dfs(v,u,3-col);
        else if(c[v]==col) {
            f = 1;
            return ;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n >> m;
    memset(head,-1,sizeof(head));
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        adde(u, v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,-1,1);
    if(f) cout << "NO";
    else {
        cout << "YES" << '\n';
        for(int i = 1;i <= n; i++) {
            for(int j = head[i]; j!=-1; j=e[j].next){
                int p = e[j].t;
                if(c[i]==1) ans[p] = 1;
            }
        }
        for(int i = 1;i <= m ; i++) {
            cout << ans[i];
        }
    }
    return 0;
}

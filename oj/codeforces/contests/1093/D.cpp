#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
typedef long long ll;
const int N = 3e5+5;
int T;
int n,m,flag,num,sum;
vector <int> g[N];
int color[N];
void dfs(int u,int c){
    color[u]=c;sum++;
    if(color[u]==1) num++;
    if(flag) return ;
    for(auto v:g[u]){
        if(!color[v]) dfs(v,3-c);
        else if(color[v]==c){
            flag=1;
            return ;
        }
    }
    return ;
}
ll quick(ll a,int b){
    ll ans = 1;
    while(b){
        if(b&1) ans=(ans*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return ans ;
}
int main(){
    cin>>T;
    while(T--){
        scanf("%d%d",&n,&m);flag=0;
        for(int i=0;i<=n;i++) g[i].clear(),color[i]=0;
        for(int i=1;i<=m;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            g[u].push_back(v);g[v].push_back(u);
        }
        int tot =0;
        ll ans =1;
        for(int i=1;i<=n;i++){
            if(!color[i] && !flag){
                num=0;sum=0;
                dfs(i,1);
                if(sum==1) ans=(ans*3)%MOD;
                else ans=(ans*(quick(2,num)+quick(2,sum-num))%MOD)%MOD;
            }
        }
        if(flag) printf("0\n");
        else printf("%I64d\n",ans);
    }
    return 0;
}


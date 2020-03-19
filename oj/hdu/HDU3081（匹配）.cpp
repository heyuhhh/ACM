 #include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
const int N = 305;
int check[N],match[N];
int n,m,f,T;
int g[N][N];
int dfs(int s){
    for(int i=n+1;i<=2*n;i++){
        if(!g[s][i] || check[i]) continue ;
        check[i]=1;
        if(match[i]==-1 || dfs(match[i])){
            match[i]=s;
            return 1;
        }
    }
    return 0;
}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&m,&f);
        memset(g,0,sizeof(g));
        for(int i=1;i<=m;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            g[u][v+n]=1;
        }
        for(int i=1;i<=f;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            g[u][v]=g[v][u]=1;
        }
        for(int k=1;k<=n;k++)
            for(int i=1;i<=n;i++)
                for(int j=1;j<=2*n;j++)
                    g[i][j]=(g[i][k]&&g[k][j])||g[i][j];
        int ans = 0,flag=0;
        while(1){
            flag = 0;
            memset(match,-1,sizeof(match));
            for(int i=1;i<=n;i++){
                memset(check,0,sizeof(check));
                if(!dfs(i)){
                    flag=1;
                    break ;
                }
            }
            if(flag) break;
            for(int i=n+1;i<=2*n;i++)
                g[match[i]][i]=0;
            ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}


#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
const int N = 105, M = 4505;
int n,m;
int mp[N][N];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        mp[u][v]=1;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                mp[i][j]=(mp[i][j]|(mp[i][k]&mp[k][j]));
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int win=0,lose=0;
        for(int j=1;j<=n;j++){
            if(mp[i][j]) win++;
            if(mp[j][i]) lose++;
        }
        if(win+lose==n-1) ans++;
    }
    cout<<ans;
    return 0;
}

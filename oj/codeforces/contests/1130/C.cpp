#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 105;
int n,cnt;
int r1,c1,r2,c2;
char mp[N][N];
int vis[N][N],bel[N][N];
struct Node{
    int x,y;
};
int dx[5]={-1,1,0,0},dy[5]={0,0,-1,1};
bool ok(int x,int y){
    return x>=1&&y>=1&&x<=n&&y<=n&&mp[x][y]=='0'&&!vis[x][y];
}
void bfs(int x,int y,int t){
    queue <Node> q;
    q.push(Node{x,y});
    vis[x][y]=1;
    while(!q.empty()){
        Node now=q.front();q.pop();
        int x=now.x,y=now.y;
        bel[x][y]=t;
        for(int i=0;i<4;i++){
            int curx=x+dx[i],cury=y+dy[i];
            if(ok(curx,cury)){
                vis[curx][cury]=1;
                q.push(Node{curx,cury});
            }
        }
    }
}
int dis(int x1,int y1,int x2,int y2){
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
int main(){
    cin>>n>>r1>>c1>>r2>>c2;
    for(int i=1;i<=n;i++){
        scanf("%s",mp[i]+1);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(mp[i][j]=='0'&&!vis[i][j]){
                bfs(i,j,++cnt);
            }
        }
    }
    int block1=bel[r1][c1],block2=bel[r2][c2];
    if(block1==block2){
        cout<<0;
        return 0;
    }
    int ans=0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(mp[i][j]=='1') continue ;
            if(bel[i][j]==block1){
                for(int p=1;p<=n;p++){
                    for(int q=1;q<=n;q++){
                        if(mp[p][q]=='1') continue ;
                        if(bel[p][q]==block2){
                            ans=min(ans,dis(i,j,p,q));
                        }
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}

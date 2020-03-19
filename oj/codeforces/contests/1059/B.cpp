#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1005;
int n,m;
char mp[N][N];
int dx[10]={1,-1,0,0,-1,1,-1};
int dy[10]={0,0,-1,1,-1,1,1};
int ok(int x,int y){
    return x>=2&&y>=2&&x<=n-1&&y<=n-1;
}
int pd(int x,int y){
    int flag=1;
    char st = mp[x+1][y-1];
    for(int i=0;i<7;i++){
        int nowx=x+dx[i],nowy=y+dy[i];
        if(mp[nowx][nowy]!=st) flag=0;
    }
    return flag;
}
int main(){
    cin>>n>>m;
    int p=1;
    for(int i=1;i<=n;i++){
        scanf("%s",mp[i]+1);
        for(int j=1;j<=m;j++){
            if(mp[i][j]=='.') p=0;
        }
    }
    if(p&&n+m<=6){
        puts("NO");
        return 0;
    }
    int flag=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mp[i][j]=='.'&&ok(i,j)&&!pd(i,j))flag=0;
        }
    }
    if(flag) puts("YES");
    else puts("NO");
    return 0;
}

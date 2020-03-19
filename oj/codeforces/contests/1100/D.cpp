#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1005;
struct node{
    int x,y;
}b[N];
int ax,ay,End;
int d[5];
int vis[N][N];
void query(int x,int y){
    printf("%d %d\n",x,y);
    fflush(stdout);
    int k,nowx,nowy;
    scanf("%d%d%d",&k,&nowx,&nowy);
    if(k==-1){
        End=1;
        exit(0);
    }
    vis[b[k].x][b[k].y]=0;
    b[k].x=nowx;b[k].y=nowy;
    vis[nowx][nowy]=1;
}
void go_mid(){
    while(1){
        if(ax==500 && ay==500) break ;
        if(ax<500) ax++;
        else if(ax>500)ax--;
        else if(ay<500)ay++;
        else if(ay>500)ay--;
        query(ax,ay);
        if(End) return ;
    }
}
int main(){
    scanf("%d%d",&ax,&ay);
    for(int i=1;i<=666;i++){
        scanf("%d%d",&b[i].x,&b[i].y);
        vis[b[i].x][b[i].y]=1;
    }
    go_mid();
    if(End) return 0;
    for(int i=1;i<=666;i++){
        int x=b[i].x,y=b[i].y;
        if(x<500){
            if(y<500) d[1]++;
            else d[0]++;
        }else{
            if(y>500) d[3]++;
            else d[2]++;
        }
    }
    int max_d,mx=100000;
    for(int i=0;i<4;i++){
        if(d[i]<mx){
            mx=d[i];
            max_d=i;
        }
    }
    int dx,dy;
    if(max_d==0) dx=1,dy=-1;
    else if(max_d==1) dx=1,dy=1;
    else if(max_d==2) dx=-1,dy=1;
    else if(max_d==3) dx=-1,dy=-1;
    while(1){
        int curx=ax+dx;
        int cury=ay+dy;
        if(vis[curx][cury]){
            ax+=dx;
            query(ax,ay);
            return 0;
        }
        ax=curx;ay=cury;
        query(ax,ay);
        if(End) return 0;
    }
    return 0;
}


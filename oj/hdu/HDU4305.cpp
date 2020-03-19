#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
const int N = 305,MOD = 10007;
int t;
int n,r;
struct Point{
    int x,y;
}p[N];
double dis(int x,int y){
    return sqrt((double)(p[x].x-p[y].x)*(p[x].x-p[y].x)+(double)(p[x].y-p[y].y)*(p[x].y-p[y].y));
}
int check(int p1,int p2){
    int x1=min(p[p1].x,p[p2].x),x2=max(p[p1].x,p[p2].x);
    if(x1==x2){
        for(int i=1;i<=n;i++){
            if(i==p1||i==p2) continue ;
            if(p[i].x==x1){
                if(p[i].y>=min(p[p1].y,p[p2].y) && p[i].y<=max(p[p1].y,p[p2].y)) return 0;
            }
        }
        return 1;
    }
    for(int i=1;i<=n;i++){
        if(i==p1||i==p2||p[i].x<x1||p[i].x>x2) continue ;
        double K = (double)(p[p2].y-p[p1].y)/(p[p2].x-p[p1].x);
        if(K==(double)(p[p2].y-p[i].y)/(p[p2].x-p[i].x)) return 0;
    }
    return 1;
}
ll b[N][N];
int g[N][N];
ll Det(int n){
    int i,j,k;
    ll ret = 1;
    for(i=2;i<=n;i++){
        for(j = i+1;j <= n;j++){
            while(b[j][i]){
                ll tmp=b[i][i]/b[j][i];//不存在除不尽的情况
                for(k = i;k <= n;k++){
                    b[i][k] = (b[i][k] - tmp*b[j][k])%MOD;
                    if(b[i][k]<0) b[i][k]+=MOD;
                }
                swap(b[i],b[j]);
                ret = -ret;
            }
        }
        if(!b[i][i]) return -1;
        ret = ret * b[i][i]%MOD;
    }
    if(ret < 0) ret += MOD;
    return ret;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&r);
        memset(g,0,sizeof(g));
        memset(b,0,sizeof(b));
        for(int i=1;i<=n;i++) scanf("%d%d",&p[i].x,&p[i].y);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j) continue ;
                if(check(i,j)&&dis(i,j)<=r) g[i][j]=g[j][i]=1;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(g[i][j]){
                    b[i][i]++;b[j][j]++;
                    b[i][j]=b[j][i]=-1;
                }
            }
        }
        cout<<Det(n)<<endl;
    }
    return 0;
}

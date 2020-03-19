#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <cmath>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int N = 505;
int t;
int s,n,tot;
struct Point{
    int x,y;
}p[N];
struct Edge{
    int u,v;
    double w;
    bool operator < (const Edge &A)const{
        return w<A.w;
    }
}e[N*N];
int f[N];
int find(int x){
    return f[x]==x?f[x]:f[x]=find(f[x]);
}
void Kruskal(){
    for(int i=0;i<=n+1;i++) f[i]=i;
    for(int i=1;i<=tot;i++){
        int fx=find(e[i].u),fy=find(e[i].v);
        if(fx==fy) continue ;
        f[fx]=fy;
    }
}
double dis(int x,int y){
    return sqrt((double)(p[x].x-p[y].x)*(p[x].x-p[y].x)+(double)(p[x].y-p[y].y)*(p[x].y-p[y].y));
}
void build(double x){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) continue ;
            if(dis(i,j)<=x){
                e[++tot].u=i;
                e[tot].v=j;
                e[tot].w=dis(i,j);
            }
        }
    }
}
bool check(double x){
    tot=0;
    build(x);
    Kruskal();
    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(f[i]==i) cnt++;
    }
    if(s>=cnt) return true;
    return false;
}
int main(){
    cin>>t;
    while(t--){
        scanf("%d%d",&s,&n);
        for(int i=1;i<=n;i++){
            scanf("%d%d",&p[i].x,&p[i].y);
        }
        double l=0,r=INF,mid;
        while(r-l>=0.00001){
            mid=(l+r)/2.0;
            if(check(mid)) r=mid;
            else l=mid+0.0001;
        }
        printf("%.2f\n",l);
    }
    return 0;
}

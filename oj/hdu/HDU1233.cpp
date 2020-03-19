#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
const int N = 105;
int n;
struct Edge{
    int u,v,w;
    bool operator < (const Edge &A)const{
        return w<A.w;
    }
}e[N*N];
int f[N];
int find(int x){
    return f[x]==x?f[x]:f[x]=find(f[x]);
}
int Kruskal(){
    int ans=0;
    for(int i=0;i<=n+1;i++) f[i]=i;
    for(int i=1;i<=n*(n-1)/2;i++){
        int fx=find(e[i].u),fy=find(e[i].v);
        if(fx==fy) continue ;
        f[fx]=fy;
        ans+=e[i].w;
    }
    return ans ;
}
int main(){
    while(~scanf("%d",&n)){
        if(n==0) break;
        for(int i=1;i<=n*(n-1)/2;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            e[i]=Edge{u,v,w};
        }
        sort(e+1,e+n*(n-1)/2+1);
        cout<<Kruskal()<<endl;
    }

    return 0;
}

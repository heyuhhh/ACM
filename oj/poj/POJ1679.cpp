#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
const int N = 105;
int t,n,m;
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
    int ans=0,cnt,j;
    for(int i=0;i<=n+1;i++) f[i]=i;
    for(int i=1;i<=m;i++){
        j=i;cnt=0;
        while(e[i].w==e[j].w && j<=m) j++,cnt++;
        for(int k=i;k<j;k++){
            int fx=find(e[k].u),fy=find(e[k].v);
            if(fx==fy) cnt--;
        }
        for(int k=i;k<j;k++){
            int fx=find(e[k].u),fy=find(e[k].v);
            if(fx!=fy){
                f[fx]=fy;
                ans+=e[i].w;
                cnt--;
            }
        }
        if(cnt>0) return -1;
    }
    return ans ;
}
int main(){
    cin>>t;
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            e[i].u=u;e[i].v=v;e[i].w=w;
        }
        sort(e+1,e+m+1);
        int ans = Kruskal();
        if(ans==-1) puts("Not Unique!");
        else printf("%d\n",ans);
    }
    return 0;
}

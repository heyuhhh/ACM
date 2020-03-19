#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int n,m;
int f[N];
struct Edge{
    int u,v,w;
    bool operator <(const Edge &A)const{
        return w<A.w;
    }
}e[N];
int find(int x){
    return f[x]==x ? f[x] : f[x]=find(f[x]);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        e[i]={u,v,w};
    }
    sort(e+1,e+m+1);
    for(int i=1;i<=n+1;i++) f[i]=i;
    int ans = 0;
    for(int i=1,j=1;i<=m;i=j){
        while(e[i].w==e[j].w) j++;
        int cnt = j-i;
        for(int k=i;k<j;k++){
            int fx=find(e[k].u),fy=find(e[k].v);
            if(fx==fy) cnt--;
        }
        for(int k=i;k<j;k++){
            int fx=find(e[k].u),fy=find(e[k].v);
            if(fx==fy) continue ;
            cnt--;
            f[fx]=fy;
        }
        ans+=cnt;
    }
    cout<<ans;
    return 0;
}

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

const int N = 1005;
int f[N],in[N],vis[N];
int find(int x){
    return f[x]==x ? x : f[x]=find(f[x]);
}
int main(){
    int u,v,end=0,tot=0;
    while(1){
        tot++;
        memset(in,0,sizeof(in));memset(vis,0,sizeof(vis));
        for(int i=1;i<=N-5;i++) f[i]=i;
        bool flag = true;
        while(cin>>u>>v){
            if(u==-1 && v==-1) end=1;
            if(u<=0 && v<=0) break;
            in[v]++;vis[u]=vis[v]=1;
            if(in[v]>1) flag=false;
            int fu=find(u),fv=find(v);
            if(fu!=fv) f[fu]=fv;
            else flag=false;
        }
        if(end) break;
        int cnt = 0;
        for(int i=1;i<=N-5;i++) if(f[i]==i &&vis[i]) cnt++;
        if(cnt>1) flag=false;
        if(!flag) printf("Case %d is not a tree.\n",tot);
        else printf("Case %d is a tree.\n",tot);
    }
    return 0;
}


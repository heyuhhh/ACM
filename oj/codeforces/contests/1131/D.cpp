#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1005;
int n,m,cnt,tot;
char mp[N][N];
int f[N<<1],num[N<<1],head[N<<1],in[N<<1],ans[N<<1];
struct Edge{
    int u,v,next;
}e[N*N<<1];
int find(int x){
    return f[x]==x?f[x]:f[x]=find(f[x]);
}
void Union(int x,int y){
    int fx=find(x),fy=find(y);
    if(fx==fy) return ;
    f[fx]=fy;
}
void adde(int u,int v){
    e[tot].v=v;e[tot].next=head[u];head[u]=tot++;
}
int topsort(){
    queue <int> q;
    int tot=0;
    for(int i=1;i<=cnt;i++) if(!in[i]) q.push(i),tot++,ans[i]=1;
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=head[u];i!=-1;i=e[i].next){
            int v=e[i].v;
            if(--in[v]==0){
                ans[v]=ans[u]+1;
                q.push(v);
                tot++;
            }
        }
    }
    return tot==cnt;
}
int main(){
    scanf("%d%d",&n,&m);
    int flag=0;
    for(int i=1;i<=n+m;i++) f[i]=i;
    for(int i=1;i<=n;i++){
        scanf("%s",mp[i]+1);
        for(int j=1;j<=m;j++){
            if(mp[i][j]=='=') Union(i,j+n);
            else flag=1;
        }
    }
    for(int i=1;i<=n+m;i++){
        int f=find(i);
        if(!num[f]) num[f]=++cnt;
    }
    if(cnt==1 && flag){
        cout<<"No";
        return 0;
    }
    memset(head,-1,sizeof(head));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int u=num[find(i)],v=num[find(j+n)];
            if(u==v&&mp[i][j]!='='){
                cout<<"No";
                return 0;
            }
            if(mp[i][j]=='<') adde(u,v),in[v]++;
            else if(mp[i][j]=='>') adde(v,u),in[u]++;
        }
    }
    int f=topsort();
    if(!f) cout<<"No";
    else{
        puts("Yes");
        for(int i=1;i<=n+m;i++){
            int fx=find(i);
            cout<<ans[num[fx]]<<" ";
            if(i==n) cout<<'\n';
        }
    }
    return 0;
}

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#define INF 99999999
#define t 50000
using namespace std;
typedef long long ll;
const int N = 305,M = 5e4+5;
int n,m,tot;
int head[M],map[N][N],num[N][N],r[M],c[M],vr[M],vc[M],d[M],pr[M],pc[M],ans[N][N];
//num:将点离散化
//r,c:离散化后的点 新的行,列
//vr,vc:行,列的值
//pr,pc:新的行,列在原图中的行列
char s[N][N][10];
struct Edge{
    int v,next,c;
}e[M];
void adde(int u,int v,int c){
    e[tot].v=v;e[tot].c=c;e[tot].next=head[u];head[u]=tot++;
    e[tot].v=u;e[tot].c=0;e[tot].next=head[v];head[v]=tot++;
}
int cal(char x,char y,char z){
    return (x-'0')*100+(y-'0')*10+z-'0';
}
int bfs(){
    memset(d,0,sizeof(d));d[0]=1;
    queue <int > q;q.push(0);
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=head[u];i!=-1;i=e[i].next){
            int v=e[i].v;
            if(e[i].c>0 && !d[v]){
                d[v]=d[u]+1;
                q.push(v);
            }
        }
    }
    return d[t]!=0;
}
int dfs(int s,int a){
    if(s==t || a==0) return a;
    int flow=0,f;
    for(int i=head[s];i!=-1;i=e[i].next){
        int v=e[i].v;
        if(d[v]!=d[s]+1) continue ;
        f=dfs(v,min(a,e[i].c));
        if(f>0){
            e[i].c-=f;
            e[i^1].c+=f;
            flow+=f;
            a-=f;
            if(a==0) break;
        }
    }
    if(!flow) d[s]=-1;
    return flow;
}
int Dinic(){
    int flow=0;
    while(bfs()) flow+=dfs(0,INF);
    return flow;
}
int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        tot =0 ;memset(head,-1,sizeof(head));memset(map,0,sizeof(map));
        memset(num,0,sizeof(num));int Num=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%s",s[i][j]);
                if(s[i][j][0]=='.') map[i][j]=1;
                else if(s[i][j][0]=='X' && s[i][j][4]=='X') map[i][j]=0;
                else map[i][j]=2;
                num[i][j]=++Num;
            }
        }
        memset(r,0,sizeof(r));memset(c,0,sizeof(c));
        memset(pr,0,sizeof(pr));memset(pc,0,sizeof(pc));
        int nr=0,nc=0;
        for(int i=1;i<=n;i++){
            int k;
            for(int j=1;j<=m;j++){
                int tmp = 0;
                if(map[i][j]==1){
                    nr++;
                    pr[nr]=i;
                    char x=s[i][j-1][4],y=s[i][j-1][5],z=s[i][j-1][6];
                    int now = cal(x,y,z);
                    vr[nr]=now;
                    for(k=j;k<=m;k++){
                        if(map[i][k]==1) r[num[i][k]]=nr,tmp++;
                        else break ;
                    }
                    j=k;
                    vr[nr]-=tmp;
                }
            }
        }
        for(int i=1;i<=m;i++){
            int k;
            for(int j=1;j<=n;j++){
                int tmp = 0;
                if(map[j][i]==1){
                    nc++;
                    pc[nc]=i;
                    char x=s[j-1][i][0],y=s[j-1][i][1],z=s[j-1][i][2];
                    int now = cal(x,y,z);
                    vc[nc]=now;
                    for(k=j;k<=n;k++){
                        if(map[k][i]==1) c[num[k][i]]=nc,tmp++;
                        else break ;
                    }
                    j=k;
                    vc[nc]-=tmp;
                }
            }
        }
        for(int i=1;i<=nr;i++) adde(0,i,vr[i]);
        for(int i=1;i<=nc;i++) adde(nr+i,t,vc[i]);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(map[i][j]==1){
                    int u=r[(i-1)*m+j],v=c[(i-1)*m+j];
                    adde(u,nr+v,8);
                }
            }
        }
        Dinic();
        memset(ans,0,sizeof(ans));
        for(int u=1;u<=nr;u++){
            for(int i=head[u];i!=-1;i=e[i].next){
                int v=e[i].v;
                if(v<=nr) continue ;
                v-=nr;
                int nowr = pr[u],nowc = pc[v];
                if(map[nowr][nowc])ans[nowr][nowc]=e[i].c;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(map[i][j]!=1) printf("_ ");
                else printf("%d ",9-ans[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}


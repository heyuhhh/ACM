int head[N];
struct Edge{
    int u,v,next;
}e[M<<1];
int T,tot;
int dfn[N],low[N],cut[N],bri[M<<1];
void adde(int u,int v){
    e[tot].u=u;e[tot].v=v;e[tot].next=head[u];head[u]=tot++;
}
void init(){
    T=0;tot=0;
    memset(head,-1,sizeof(head));
    memset(cut,0,sizeof(cut));
    memset(dfn,0,sizeof(dfn));
    memset(bri,0,sizeof(bri));
}
void Tarjan(int u,int pre){
    dfn[u]=low[u]=++T;
    int son=0;
    for(int i=head[u];i!=-1;i=e[i].next){
        int v=e[i].v;
        if(v==pre) continue ;
        if(!dfn[v]){
            son++;//起点有效儿子
            Tarjan(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>=dfn[u]&&u!=pre)cut[u]=1;
            if(low[v]>dfn[u]){
                bri[i]=1;bri[i^1]=1;
            }
        }else{
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(u==pre && son>1) cut[u]=1;
}

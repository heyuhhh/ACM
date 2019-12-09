struct Edge{
    int u,v,w,next;
}e[M<<1];
int tot;
void adde(int u,int v,int w){
    e[tot].u=u;e[tot].v=v;e[tot].w=w;e[tot].next=head[u];head[u]=tot++;
}
int spfa(int s){
    queue <int> q;
    memset(d,INF,sizeof(d));
    memset(vis,0,sizeof(vis));memset(c,0,sizeof(c));
    q.push(s);vis[s]=1;d[s]=0;c[s]=1;
    while(!q.empty()){
        int u=q.front();q.pop();vis[u]=0;
        if(c[u]>n){
            return -1;
        }
        for(int i=head[u];i!=-1;i=e[i].next){
            int v=e[i].v;
            if(d[v]>d[u]+e[i].w){
                d[v]=d[u]+e[i].w;
                fa[v]=u;
                if(!vis[v]){
                    vis[v]=1;
                    q.push(v);
                    c[v]++;
                }
            }
        }
    }
    return d[n];
}

//�����㷨����С���������������Ӷ�$O(nm)$��
struct Edge{
    int u,v,w;
}e[M];
int pre[N]; //��¼ǰ��.
int id[N],vis[N],in[N];
int dirMst(int root){
    int ans=0;
    while(1){
        memset(in,INF,sizeof(in));
        memset(id,-1,sizeof(id));
        memset(vis,-1,sizeof(vis));
        for(int i=1;i<=m;i++){
            int u=e[i].u,v=e[i].v,w=e[i].w;
            if(w<in[v] && v!=u){
                pre[v]=u;
                in[v]=w;
            }
        }           //����С��߼�
        in[root]=0;
        pre[root]=root;
        for(int i=0;i<n;i++){
            if(in[i]==INF) return -1;
            ans+=in[i];
        }
        int idx = 0; //�±��
        for(int i=0;i<n;i++){
            if(vis[i] == -1 ){
                int u = i;
                while(vis[u] == -1){
                    vis[u] = i;
                    u = pre[u];
                }
                if(vis[u]!=i || u==root) continue;     //�ж��Ƿ��γɻ�
                for(int v=pre[u];v!=u;v=pre[v] )
                    id[v]=idx;
                id[u] = idx++;
            }
        }
        if(idx==0) break;
        for(int i=0;i<n;i++){
            if(id[i]==-1) id[i]=idx++;
        }
        for(int i=1;i<=m;i++){
            e[i].w-=in[e[i].v];
            e[i].u=id[e[i].u];
            e[i].v=id[e[i].v];
        }
        n = idx;
        root = id[root];//�����µı��
    }
    return ans;
} 

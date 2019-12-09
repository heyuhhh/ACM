int link[N][N],vis[N],group[N],cnt[N];
int ans ;
int dfs(int x,int tot){
    for(int i=x+1;i<=n;i++){
        if(cnt[i]+tot<=ans) return 0;//¼ôÖ¦1 
        if(link[x][i]){
            int flag = 0;
            for(int j=0;j<tot;j++){
                if(!link[i][vis[j]]) flag=1;
            }
            if(!flag){
                vis[tot]=i;
                if(dfs(i,tot+1)) return 1;//¼ôÖ¦2 
            }
        }
    }
    if(tot>ans){
        ans=tot;
        for(int i=0;i<tot;i++) group[i]=vis[i];
        return 1;
    }
    return 0;
}
void maxclique(){
    ans=-1;
    memset(cnt,0,sizeof(cnt));
    for(int i=n;i>=1;i--){
        vis[0]=i;
        dfs(i,1);
        cnt[i]=ans;
    }
}

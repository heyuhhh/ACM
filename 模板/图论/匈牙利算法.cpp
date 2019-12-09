int match[N],check[N]; 
int dfs(int x,int nown){
    for(int i=1;i<=nown;i++){
        if(!check[i] && link[x][i]){
            check[i]=1;
            if(match[i]==-1 || dfs(match[i],nown)){
                match[i]=x;
                return 1;
            }
        }
    }
    return 0;
}
int hungry(int n1,int m1){
    memset(match,-1,sizeof(match));
    int ans=0;
    for(int i=1;i<=n1;i++){
        memset(check,0,sizeof(check));
        ans+=dfs(i,m1);
    }
    return ans ;
} 

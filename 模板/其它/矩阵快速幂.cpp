struct matrix{
    ll A[N][N];
    int n,m;
    matrix(){
        memset(A,0,sizeof(A));
    }
    void Print(){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout<<A[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};
matrix operator * (const matrix &a,const matrix &b){
    matrix ans;
    ans.n=a.n;ans.m=b.m;
    for(int i=1;i<=ans.n;i++){
        for(int j=1;j<=ans.m;j++){
            for(int k=1;k<=b.n;k++){
                ans.A[i][j]=(ans.A[i][j]+a.A[i][k]*b.A[k][j]%MOD)%MOD;
            }
        }
    }
    return ans ;
}
matrix operator + (const matrix &a,const matrix &b){
    matrix ans;
    ans.n=a.n;ans.m=a.m;
    for(int i=1;i<=ans.n;i++){
        for(int j=1;j<=ans.m;j++){
            ans.A[i][j]=(a.A[i][j]+b.A[i][j])%MOD;
        }
    }
    return ans ;
}
matrix qp_Mat(matrix a,ll b){
    matrix ans;
    ans.n=ans.m=a.n;
    for(int i=1;i<=ans.n;i++) ans.A[i][i]=1;
    while(b){
        if(b&1) ans=ans*a;
        a=a*a;
        b>>=1;
    }
    return ans ;
} 

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 55,MOD = 10000;
int n,m,st,en,F;
ll k;
ll mp[N][N],b[N],ans[N][N];
struct matrix{
    ll A[N][N];
    int n,m;
    matrix(){
        memset(A,0,sizeof(A));
    }
    void eye(){
        for(int i=1;i<=n;i++) A[i][i]=1;
    }
    void Print(){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout<<A[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}a[20];
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
int main(){
    cin>>n>>m>>st>>en>>k;
    st++;en++;
    for(int i=0;i<=12;i++) a[i].n=a[i].m=n;
    for(int i=1;i<=m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        u++;v++;
        for(int j=1;j<=12;j++) a[j].A[u][v]=a[j].A[v][u]=1;
    }
    scanf("%d",&F);
    for(int i=1,K;i<=F;i++){
        scanf("%d",&K);
        for(int j=0;j<K;j++) cin>>b[j],b[j]++;
        for(int j=1;j<=12;j++){
            int now=j%K;
            for(int kk=1;kk<=n;kk++) a[j].A[kk][b[now]]=0;
        }
    }
    matrix Mat,Ans;
    Mat.n=Mat.m=Ans.n=Ans.m=n;
    a[0].eye();
    for(int i=1;i<=12;i++){
        a[0]=a[0]*a[i];
    }
    Ans=qp_Mat(a[0],k/12);
    if(k%12==0){
        printf("%d",Ans.A[st][en]);
        return 0;
    }
    int r=k%12;
    for(int i=1;i<=r;i++) Ans=Ans*a[i];
    printf("%d",Ans.A[st][en]);
    return 0;
}
?

#include<bits/stdc++.h>
using namespace std;
const int inf=1000000007;
int a[305][305],d[2][305][305],n,m,x[305],y[305],z[305],k,f[305],ans;
int w[305][305][3],o;
const int T=1000;
mt19937 gen(time(0)^19260817);
void Max(int &x,int y){if (y>x) x=y;}
void ins(int x,int y,int z){
    int p=0;
    while (p<3){
        int u=w[x][y][p];
        if (a[x][u]+a[u][y]<a[x][z]+a[z][y]) break;
        p++;
    }
    if (p<3){
        for (int i=2;i>p;i--) w[x][y][i]=w[x][y][i-1];
        w[x][y][p]=z;
    }
}
void work(int x,int y,int u,int v){
    int p=0;
    while (w[u][v][p]==x||w[u][v][p]==y) ++p;
    int z=w[u][v][p];
    Max(d[o][x][y],a[x][u]+a[u][z]+a[z][v]+a[v][y]);
}
void solve(int k){
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            d[o][i][j]=-inf;
    if (k==1){
        for (int i=1;i<=n;i++) if (f[i]==o) d[o][i][i]=0;
    } else if (k==2){
        for (int i=1;i<=n;i++) if (f[i]==o)
        for (int j=1;j<=n;j++) if (i!=j&&f[j]==o)
            d[o][i][j]=a[i][j];
    } else if (k==3){
        for (int i=1;i<=m;i++) if (f[x[i]]==o&&f[y[i]]==o)
        for (int j=1;j<=m;j++) if (f[x[j]]==o&&f[y[j]]==o){
            if (i==j) continue;
            if (x[i]==x[j]) Max(d[o][y[i]][y[j]],z[i]+z[j]);
            else if (x[i]==y[j]) Max(d[o][y[i]][x[j]],z[i]+z[j]);
            else if (y[i]==x[j]) Max(d[o][x[i]][y[j]],z[i]+z[j]);
            else if (y[i]==y[j]) Max(d[o][x[i]][x[j]],z[i]+z[j]);
        }
    } else if (k==4){
        for (int i=1;i<=m;i++) if (f[x[i]]==o&&f[y[i]]==o)
        for (int j=1;j<=m;j++) if (f[x[j]]==o&&f[y[j]]==o){
            if (i==j) continue;
            if (x[i]==x[j]) continue;
            if (x[i]==y[j]) continue;
            if (y[i]==x[j]) continue;
            if (y[i]==y[j]) continue;
            if (x[i]!=x[j]) Max(d[o][x[i]][x[j]],z[i]+z[j]+a[y[i]][y[j]]);
            if (x[i]!=y[j]) Max(d[o][x[i]][y[j]],z[i]+z[j]+a[y[i]][x[j]]);
            if (y[i]!=x[j]) Max(d[o][y[i]][x[j]],z[i]+z[j]+a[x[i]][y[j]]);
            if (y[i]!=y[j]) Max(d[o][y[i]][y[j]],z[i]+z[j]+a[x[i]][x[j]]);
        }
    } else if (k==5){
        for (int i=1;i<=n;i++) if (f[i]==o)
        for (int j=1;j<=n;j++) if (f[j]==o)
            w[i][j][0]=w[i][j][1]=w[i][j][2]=0;

        for (int i=1;i<=m;i++) if (f[x[i]]==o&&f[y[i]]==o)
        for (int j=1;j<=m;j++) if (f[x[j]]==o&&f[y[j]]==o){
            if (i==j) continue;
            if (x[i]==x[j]) ins(y[i],y[j],x[i]);
            else if (x[i]==y[j]) ins(y[i],x[j],x[i]);
            else if (y[i]==x[j]) ins(x[i],y[j],x[j]);
            else if (y[i]==y[j]) ins(x[i],x[j],y[j]);
        }
        for (int i=1;i<=m;i++) if (f[x[i]]==o&&f[y[i]]==o)
        for (int j=1;j<=m;j++) if (f[x[j]]==o&&f[y[j]]==o){
            if (i==j) continue;
            if (x[i]==x[j]) continue;
            if (x[i]==y[j]) continue;
            if (y[i]==x[j]) continue;
            if (y[i]==y[j]) continue;
            work(x[i],x[j],y[i],y[j]);
            work(x[i],y[j],y[i],x[j]);
            work(y[i],x[j],x[i],y[j]);
            work(y[i],y[j],x[i],x[j]);
        }
    }
    if (k!=1) for (int i=1;i<=n;i++) d[o][i][i]=-inf;
}

int main(){
    cin >> n >> m >> k;
    for (int i=0;i<=n;i++)
        for (int j=0;j<=n;j++)
            a[i][j]=-inf;
    for (int i=1;i<=m;i++){
        cin >> x[i] >> y[i] >> z[i];
        a[x[i]][y[i]]=a[y[i]][x[i]]=z[i];
    }
    for (int _=0;_<T;_++){
        for (int i=1;i<=n;i++) f[i]=gen()%2;
        if (k==6){
            o=0; solve(2); o=1; solve(4);
        } else {
            o=0; solve(k/2); o=1; solve(k-k/2);
        }
        for (int i=1;i<=m;i++) if (f[x[i]]^f[y[i]]){
            if (f[x[i]]) swap(x[i],y[i]);
        }
        for (int i=1;i<=m;i++) if (f[x[i]]^f[y[i]])
        for (int j=1;j<=m;j++) if (f[x[j]]^f[y[j]]){
            //if (x[i]==x[j]||y[i]==y[j]) continue;
            ans=max(ans,d[0][x[i]][x[j]]+d[1][y[i]][y[j]]+z[i]+z[j]);
        }
    }
    if (ans>0) cout << ans << endl; else puts("impossible");
    return 0;
}

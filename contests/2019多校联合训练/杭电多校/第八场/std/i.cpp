#include<bits/stdc++.h>
using namespace std;
int T,x[4],y[4],tot,r[10][10],c[10][10],pre[100],X,Y,ans;
set <int> s;
map <int,int> f;
int ffind(int x){if (pre[x]==x) return x;pre[x]=ffind(pre[x]);return pre[x];}
int main(){
    cin >> T;
    while (T--){
        for (int i=0;i<4;i++) cin >> x[i] >> y[i];
        for (int i=0;i<4;i++) if (s.find(x[i])==s.end()) s.insert(x[i]);
        for (auto x:s) f[x]=++tot; X=tot+1; tot=0; s.clear();
        for (int i=0;i<4;i++) x[i]=f[x[i]]; f.clear();
        for (int i=0;i<4;i++) if (s.find(y[i])==s.end()) s.insert(y[i]);
        for (auto y:s) f[y]=++tot; Y=tot+1; tot=0; s.clear();
        for (int i=0;i<4;i++) y[i]=f[y[i]]; f.clear();
        memset(r,0,sizeof(r));memset(c,0,sizeof(c));
        for (int i=x[0];i<x[1];i++) r[i][y[0]]=r[i][y[1]]=1;
        for (int i=y[0];i<y[1];i++) c[x[0]][i]=c[x[1]][i]=1;
        for (int i=x[2];i<x[3];i++) r[i][y[2]]=r[i][y[3]]=1;
        for (int i=y[2];i<y[3];i++) c[x[2]][i]=c[x[3]][i]=1;
        for (int i=0;i<X*Y;i++) pre[i]=i; ans=X*Y;
        for (int i=1;i<X;i++)
        for (int j=0;j<Y;j++) if (!c[i][j]){
            int u=(i-1)*Y+j,v=i*Y+j;
            u=ffind(u); v=ffind(v);
            if (u!=v) pre[v]=u,ans--;
        }
        for (int i=0;i<X;i++)
        for (int j=1;j<Y;j++) if (!r[i][j]){
            int u=i*Y+(j-1),v=i*Y+j;
            u=ffind(u); v=ffind(v);
            if (u!=v) pre[v]=u,ans--;
        }
        cout << ans << endl;
    }
    return 0;
}

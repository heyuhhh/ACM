#include<bits/stdc++.h>
using namespace std;
 
#define N 400005
 
#define pb push_back
int fa[N];
struct pa {
    int x,y;
}a[N];
struct node {
    int x,y,z;
}b[N];
vector<int>A[N],G[N];
int ans[N],tot,n,m,Q;
vector<pa>T[N];
 
map<int,int>ma[N],Ma[N];
 
int q[N];
 
inline int get(int x) {
    int r=0;
    while (fa[x]!=x) q[++r]=x,x=fa[x];
    while (r) fa[q[r]]=x,r--;
    return x;
}
 
inline bool cmp(node x,node y) {
    return x.z<y.z;
}
 
inline int combine(int x,int y) {
    if (A[x].size()>A[y].size()) swap(x,y);
    for (auto p:A[x]) {
        if (ans[p]) continue;
        A[y].pb(p);
    }
    return y;
}
 
inline void combine(int x,int y,int v) {
    for (auto p:T[x]) {
        if (ans[p.y]) continue;
        if (Ma[y][get(p.x)]) ans[p.y]=v;
        else T[y].pb(p);
    }
    for (auto q:G[x]) {
        int p=get(q);
        int l=min(p,y),r=max(p,y);
        for (auto q:A[ma[l][r]]) {
            if (ans[q]) continue;
            ans[q]=v;
        }
        //A[ma[p][y].clear();
        if (!Ma[y][p]) {
            G[y].pb(p);
            G[p].pb(y);
            Ma[y][p]=Ma[p][y]=1;
        }
    }
    for (auto q:T[x]) {
        int p=get(q.x);
        if (p==y) continue;
        if (x==y) continue;
        if (ans[q.y]) continue;
        int l=min(p,y),r=max(p,y);
        int L=min(p,x),R=max(p,x);
        if (!ma[l][r]) ma[l][r]=ma[L][R];
        else if (ma[l][r]!=ma[L][R])
        ma[l][r]=combine(ma[l][r],ma[L][R]);
    }
    fa[x]=y;
}
 
int main() {
    int test;
    scanf("%d",&test);
    while (test--) {
        scanf("%d%d%d",&n,&m,&Q);
        for (int i=1;i<=m;i++) {
            scanf("%d%d%d",&b[i].x,&b[i].y,&b[i].z);
            G[b[i].x].pb(b[i].y);
            G[b[i].y].pb(b[i].x);
            Ma[b[i].y][b[i].x]=1;
            Ma[b[i].x][b[i].y]=1;
        }
        sort(b+1,b+1+m,cmp);
        for (int i=1;i<=n;i++) fa[i]=i,Ma[i][i]=1;
        for (int i=1;i<=Q;i++) {
            ans[i]=0;
            scanf("%d%d",&a[i].x,&a[i].y);
            if (Ma[a[i].x][a[i].y]) {
                ans[i]=1;
                continue;
            }
            T[a[i].x].pb(pa{a[i].y,i});
            T[a[i].y].pb(pa{a[i].x,i});
            if (a[i].x>a[i].y) swap(a[i].x,a[i].y);
            if (!ma[a[i].x][a[i].y]) ma[a[i].x][a[i].y]=++tot;
            A[ma[a[i].x][a[i].y]].pb(i);
        }
        for (int i=1;i<=m;i++) {
            b[i].x=get(b[i].x),b[i].y=get(b[i].y);
            if (get(b[i].x)==get(b[i].y)) continue;
            if (T[b[i].x].size()+G[b[i].x].size()>T[b[i].y].size()+G[b[i].y].size())
            swap(b[i].x,b[i].y);
            combine(b[i].x,b[i].y,b[i].z+1);
        }
        for (int i=1;i<=Q;i++) printf("%d\n",ans[i]-1);
        for (int i=1;i<=tot;i++) A[i].clear();
        tot=0;
        for (int i=1;i<=n;i++) ma[i].clear(),Ma[i].clear(),T[i].clear(),G[i].clear();
    }
}
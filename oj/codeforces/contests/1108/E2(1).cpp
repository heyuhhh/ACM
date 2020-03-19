#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int N = 1e5+5,M = 305;
int a[N],l[N],r[N],b[N],c[N];
int n,m,tot;
int mx[N],mn[N];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&l[i],&r[i]);
        r[i]++;
        b[++tot]=l[i];
        b[++tot]=r[i];
    }
    b[++tot]=1;b[++tot]=n+1;
    sort(b+1,b+tot+1);
    tot = unique(b+1,b+tot+1)-(b+1);
    for(int i=1;i<=m;i++){
        l[i]=lower_bound(b+1,b+tot+1,l[i])-b;
        r[i]=lower_bound(b+1,b+tot+1,r[i])-b;
    }
    int t1=-INF,t2=INF;
    for(int i=1;i<tot;i++){
        mx[i]=mn[i]=a[b[i]];
        for(int j=b[i]+1;j<b[i+1];j++){
            mx[i]=max(mx[i],a[j]);
            mn[i]=min(mn[i],a[j]);
        }
        t1=max(t1,mx[i]);t2=min(t2,mn[i]);
    }
    vector <int> ans[N];
    int Ans=t1-t2,pos=0;
    for(int x=1;x<tot;x++){
        memset(c,0,sizeof(c));
        for(int j=1;j<=m;j++){
            if(l[j]<=x && r[j]>x)
                ans[x].push_back(j);
        }
        if(!ans[x].size()) continue ;
        for(auto v:ans[x]){
            c[l[v]]--;c[r[v]]++;
        }
        int s = 0,minx = INF,t=0,maxx=-INF;
        for(int i=1;i<tot;i++){
            s+=c[i];
            if(!t || mn[i]+s<minx) minx=mn[t=i]+s;
        }
        s = 0;
        for(int i=1;i<tot;i++){
            s+=c[i];
            if(mx[i]+s>maxx) maxx=mx[i]+s;
        }
        if(maxx-minx>Ans){
            Ans=maxx-minx;
            pos=x;
        }
    }
    cout<<Ans<<endl<<ans[pos].size()<<endl;
    for(auto v:ans[pos]) cout<<v<<" ";
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
struct node{
    ll a,c,id;
    bool operator < (const node &A)const{
        if(A.c==c) return id>A.id;
        return c>A.c;
    }
};
priority_queue <node> q;
int n,m;
ll a[N],c[N];
ll ans[N];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) scanf("%I64d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%I64d",&c[i]);
    for(int i=1;i<=n;i++) q.push(node{a[i],c[i],i});
    for(int i=1;i<=m;i++){
        ll t,d;
        scanf("%I64d%I64d",&t,&d);
        ll mn = min(a[t],d);
        a[t]-=mn;
        d-=mn;
        ans[i]+=mn*c[t];
        while(!q.empty() && d){
            node now = q.top();q.pop();
            if(a[now.id]==0) continue ;
            mn = min(d,a[now.id]);
            a[now.id]-=mn;
            d-=mn;
            ans[i]+=mn*c[now.id];
            if(a[now.id]) q.push(node{a[now.id],c[now.id],now.id});
        }
        if(d) ans[i]=0;
    }
    for(int i=1;i<=m;i++) printf("%I64d\n",ans[i]);
    return 0;
}

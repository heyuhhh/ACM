#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 100005;
ll n,m;
ll a[N];
struct Tree{
    ll l,r;
    ll lazy,sum;
}tre[N<<3];
ll in[N],out[N],head[N],f[N<<1];
ll c[N<<1],num[N<<1];
ll dfn,tot;
struct Edge{
    ll u,v,next;
}e[N<<1];
void adde(ll u,ll v){
    e[tot].v=v;e[tot].next=head[u];head[u]=tot++;
}
void dfs(ll u,ll fa){
    in[u]=++dfn;
    num[dfn]=u;f[dfn]=1;
    for(ll i=head[u];i!=-1;i=e[i].next){
        ll v=e[i].v;
        if(v!=fa) dfs(v,u);
    }
    out[u]=++dfn;
    num[dfn]=u;f[dfn]=-1;
}
void build(ll rt,ll l,ll r){
    tre[rt].l=l;tre[rt].r=r;
    ll mid=(l+r)>>1;
    if(l==r){
        tre[rt].sum=f[l]*a[num[l]];
        return ;
    }
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
    tre[rt].sum=tre[rt<<1].sum+tre[rt<<1|1].sum;
}
void push_down(ll rt){
    ll lazy=tre[rt].lazy;
    tre[rt<<1].sum+=lazy*(c[tre[rt<<1].r]-c[tre[rt<<1].l-1]);
    tre[rt<<1|1].sum+=lazy*(c[tre[rt<<1|1].r]-c[tre[rt<<1|1].l-1]);
    tre[rt<<1].lazy+=lazy;
    tre[rt<<1|1].lazy+=lazy;
    tre[rt].lazy=0;
    return ;
}
void add(ll rt,ll id,ll z){
    ll l=tre[rt].l,r=tre[rt].r;
    if(l==id&&r==id){
        tre[rt].sum+=z;
        return ;
    }
    push_down(rt);
    ll mid=(l+r)>>1;
    if(mid>=id) add(rt<<1,id,z);
    else add(rt<<1|1,id,z);
    tre[rt].sum=tre[rt<<1].sum+tre[rt<<1|1].sum;
    return ;
}
void update(ll rt,ll l,ll r,ll z){
    ll L=tre[rt].l,R=tre[rt].r;
    if(l<=L && R<=r){
        tre[rt].sum+=(c[R]-c[L-1])*(ll)z;
        tre[rt].lazy+=z;
        return ;
    }
    if(tre[rt].lazy) push_down(rt);
    ll mid=(L+R)>>1;
    if(l<=mid) update(rt<<1,l,r,z);
    if(r>mid) update(rt<<1|1,l,r,z);
    tre[rt].sum=tre[rt<<1].sum+tre[rt<<1|1].sum;
    return ;
}
ll query(ll rt,ll l,ll r){
    ll res = 0;
    ll L=tre[rt].l,R=tre[rt].r;
    if(l<=L&&R<=r){
        return tre[rt].sum;
    }
    if(tre[rt].lazy) push_down(rt);
    ll mid=(L+R)>>1;
    if(l<=mid) res+=query(rt<<1,l,r);
    if(r>mid) res+=query(rt<<1|1,l,r);
    return res ;
}
int main(){
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    memset(head,-1,sizeof(head));
    for(ll i=1;i<n;i++){
        ll u,v;
        scanf("%lld%lld",&u,&v);
        adde(u,v);adde(v,u);
    }
    dfs(1,-1);
    for(ll i=1;i<=dfn;i++) c[i]=c[i-1]+f[i];
    build(1,1,2*n);
    for(ll i=1;i<=m;i++){
        ll op,x,z;
        scanf("%lld",&op);
        if(op==1){
            scanf("%lld%lld",&x,&z);
            add(1,in[x],z);
            add(1,out[x],-z);
        }else if(op==2){
            scanf("%lld%lld",&x,&z);
            update(1,in[x],out[x],z);
        }else{
            scanf("%lld",&x);
            printf("%lld\n",query(1,1,in[x]));
        }
    }
    return 0;
}


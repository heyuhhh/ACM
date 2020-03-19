#include <bits/stdc++.h>
#define INF 999999999999999
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int n;
ll a[N],b[N],t[N],k[N],pre[N];
struct Seg_Tre{
    int l,r;
    ll lazy,sum,mx;
}tre[N<<2];
void push_up(int rt){
    tre[rt].sum=tre[rt<<1].sum+tre[rt<<1|1].sum;
    tre[rt].mx=max(tre[rt<<1].mx,tre[rt<<1|1].mx);
}
void push_down(int rt){
    if(tre[rt].lazy!=INF){
        ll lzy=tre[rt].lazy;
        tre[rt<<1].sum=lzy*(tre[rt<<1].r-tre[rt<<1].l+1);
        tre[rt<<1|1].sum=lzy*(tre[rt<<1|1].r-tre[rt<<1|1].l+1);
        tre[rt<<1].mx=lzy;
        tre[rt<<1|1].mx=lzy;
        tre[rt].lazy=INF;
        tre[rt<<1].lazy=lzy;tre[rt<<1|1].lazy=lzy;
    }
}
void build(int rt,int l,int r){
    tre[rt].l=l;tre[rt].r=r;tre[rt].lazy=INF;
    if(l==r){
        tre[rt].sum=tre[rt].mx=b[l];
        return ;
    }
    int mid = l+r>>1;
    build(rt<<1,l,mid);build(rt<<1|1,mid+1,r);
    push_up(rt);
}
ll query_sum(int rt,int l,int r){
    int L=tre[rt].l,R=tre[rt].r;int mid=L+R>>1;
    if(l<=L&&R<=r){
        return tre[rt].sum;
    }
    push_down(rt);
    ll ans = 0;
    if(l<=mid) ans+=query_sum(rt<<1,l,r);
    if(r>mid) ans+=query_sum(rt<<1|1,l,r);
    push_up(rt);
    return ans ;
}
ll query_pos(int rt,ll val){
    int L=tre[rt].l,R=tre[rt].r;
    int mid=L+R>>1;
    if(L==R) return L;
    ll p;
    push_down(rt);
    if(tre[rt<<1].mx>=val) p=query_pos(rt<<1,val);
    else p=query_pos(rt<<1|1,val);
    return p;
}
void update(int rt,int l,int r,ll val){
    int L=tre[rt].l,R=tre[rt].r;
    int mid=L+R>>1;
    if(l<=L&&R<=r){
        tre[rt].lazy=val;
        tre[rt].sum=val*(R-L+1);
        tre[rt].mx=val;
        return ;
    }
    push_down(rt);
    if(l<=mid) update(rt<<1,l,r,val);
    if(r>mid) update(rt<<1|1,l,r,val);
    push_up(rt);
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<n;i++){
        cin>>k[i];
        k[i]+=k[i-1];
        pre[i]=pre[i-1]+k[i];
    }
    for(int i=1;i<=n;i++) b[i]=a[i]-k[i-1];
    build(1,1,n);
    int q,x,y;char c;
    cin>>q;
    while(q--){
        //getchar();
        cin>>c>>x>>y;
        if(c=='s'){
            ll ans = query_sum(1,x,y);
            cout<<ans+pre[y-1]-(x>=2?pre[x-2]:0)<< '\n';
        }else{
            ll st = query_sum(1,n,n);
            ll now = query_sum(1,x,x)+y;
            ll r = query_pos(1,now);
            if(r==n && st<now) r=n+1;
            update(1,x,r-1,now);
            //cout<<x<<" "<<r<<" "<<now+y<< '\n';
        }
    }
    return 0;
}

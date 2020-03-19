#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
int n,m;
ll a[N];
ll ans;
struct Tree{
    int l,r;
    ll f,w;
}tre[(N<<2)+1];
void build(int o,int l,int r){
    tre[o].l=l;tre[o].r=r;tre[o].f=0;
    if(l==r){
        tre[o].w=a[l];
        return ;
    }
    int mid=l+r>>1;
    build(o<<1,l,mid);
    build(o<<1|1,mid+1,r);
    tre[o].w=tre[o<<1].w+tre[o<<1|1].w;
}
void down(int o){
    tre[o<<1].f+=tre[o].f;
    tre[o<<1|1].f+=tre[o].f;
    tre[o<<1].w+=tre[o].f*(tre[o<<1].r-tre[o<<1].l+1);
    tre[o<<1|1].w+=tre[o].f*(tre[o<<1|1].r-tre[o<<1|1].l+1);
    tre[o].f=0;
}
void update(int o,int l,int r,int val){
    int L=tre[o].l,R=tre[o].r;
    if(L>=l && R<=r){
        tre[o].w+=(ll)val*(R-L+1);
        tre[o].f+=val;
        return ;
    }
    down(o);
    int mid=L+R>>1;
    if(l<=mid) update(o<<1,l,r,val);
    if(r>mid) update(o<<1|1,l,r,val);
    tre[o].w=tre[o<<1].w+tre[o<<1|1].w;
}
void query(int o,int l,int r){
    int L=tre[o].l,R=tre[o].r;
    if(L>=l && R<=r){
        ans+=tre[o].w;
        return ;
    }
    down(o);
    int mid=L+R>>1;
    if(l<=mid) query(o<<1,l,r);
    if(r>mid) query(o<<1|1,l,r);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%I64d",&a[i]);
    build(1,1,n);
    char s[5];
    for(int i=1;i<=m;i++){
        scanf("%s",s);
        if(s[0]=='Q'){
            int l,r;ans=0;
            scanf("%d%d",&l,&r);
            query(1,l,r);
            printf("%I64d\n",ans);
        }else{
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            update(1,a,b,c);
        }
    }
    return 0;
}

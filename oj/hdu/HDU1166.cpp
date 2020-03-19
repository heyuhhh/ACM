#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
const int N = 50005;
int t;
int n,ans;
int a[N];
struct tree{
    int l,r,w,f;
}tre[N*4+1];
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
void add(int o,int pos,int val){
    if(tre[o].l==pos && tre[o].r==pos){
        tre[o].w+=val;
        return ;
    }
    int mid=tre[o].l+tre[o].r>>1;
    if(pos<=mid) add(o<<1,pos,val);
    else add(o<<1|1,pos,val);
    tre[o].w=tre[o<<1].w+tre[o<<1|1].w;
}
void query(int o,int l,int r){
    if(tre[o].l>=l && tre[o].r<=r){
        ans+=tre[o].w;
        return ;
    }
    int mid=tre[o].l+tre[o].r>>1;
    if(l<=mid) query(o<<1,l,r);
    if(r>mid) query(o<<1|1,l,r);
}
int main(){
    scanf("%d",&t);
    int Case=0;
    while(t--){
        Case++;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        build(1,1,n);
        char s[15];
        printf("Case %d:\n",Case);
        while(1){
            scanf("%s",s);
            if(s[0]=='E') break ;
            int pos,d;
            scanf("%d%d",&pos,&d);
            if(s[0]=='A'){
                add(1,pos,d);
            }else if(s[0]=='S'){
                add(1,pos,-d);
            }else{
                ans=0;
                query(1,pos,d);
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}

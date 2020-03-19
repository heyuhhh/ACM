#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
const int N = 50005,M = 200005,MAX=1000010;
int n,m;
int a[N],c[N],b[M];
int pos[MAX];
int lowbit(int x){
    return x&(-x);
}
void add(int x,int p){
    for(int i=x;i<=50000;i+=lowbit(i)) c[i]+=p;
}
int query(int x){
    int ans = 0;
    for(int i=x;i>0;i-=lowbit(i)) ans+=c[i];
    return ans ;
}
struct Qeury{
    int l,r,id;
    bool operator < (const Qeury &A)const{
        if(r==A.r) return l<A.l;
        return r<A.r;
    }
}q[M];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i]++;
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&q[i].l,&q[i].r);
        q[i].id=i;
    }
    sort(q+1,q+m+1);
    int cnt = 1;
    for(int i=1;i<=n;i++){
        if(pos[a[i]]){
            add(pos[a[i]],-1);
            add(i,1);
            pos[a[i]]=i;
        }else{
            add(i,1);
            pos[a[i]]=i;
        }
        while(i==q[cnt].r){
            int l=q[cnt].l,r=q[cnt].r;
            int ans = query(r)-query(l-1);
            b[q[cnt].id]=ans;
            cnt++;
        }
    }
    for(int i=1;i<=m;i++) printf("%d\n",b[i]);
    return 0;
}

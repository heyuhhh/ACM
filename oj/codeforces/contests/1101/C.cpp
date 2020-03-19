#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int n;
struct Seg{
    int l,r,id;
    bool operator < (const Seg &A)const{
        return l<A.l;
    }
}seg[N];
int T;
int ans[N],a[N];
int main(){
    cin>>T;
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d%d",&seg[i].l,&seg[i].r);
            seg[i].id=i;
            a[i]=0;
        }
        sort(seg+1,seg+n+1);
        int t=1;
        int max_r = 0;
        a[0]=1;
        for(int i=1;i<n;i++){
            max_r = max(max_r,seg[i].r);
            if(!a[i]) a[i]=a[i-1];
            if(max_r<seg[i+1].l){
                t++;
                a[i+1]=t;
            }
        }
        if(!a[n]) a[n]=a[n-1];
        if(t<2) puts("-1");
        else{
            for(int i=1;i<=n;i++){
                if(a[i]<t) ans[seg[i].id]=1;
                else ans[seg[i].id]=2;
            }
            for(int i=1;i<=n;i++) printf("%d ",ans[i]);
            printf("\n");
        }
    }
    return 0;
}

#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int N = 1005;
int n,r,cnt;
int a[N],dp[N];
struct Edge{
    int l,r;
    bool operator < (const Edge &A)const{
        return l<A.l;
    }
}seg[N];
int main(){
    scanf("%d%d",&n,&r);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]==1){
            seg[++cnt].l=max(1,i-r+1);
            seg[cnt].r=min(n,i+r-1);
        }
    }
    sort(seg+1,seg+cnt+1);
    memset(dp,INF,sizeof(dp));
    for(int i=1;i<=cnt;i++)
        if(seg[i].l==1) dp[seg[i].r]=1;
    for(int i=2;i<=cnt;i++){
        int tmp = 0;
        for(int j=1;j<i;j++){
            int l1 = seg[i].l,r1 = seg[i].r;
            int l2 = seg[j].l,r2 = seg[j].r;
            if(r1<=r2) break ;
            if(r2>=l1-1) dp[r1]=min(dp[r1],dp[r2]+1);
        }
    }
    if(dp[n]==INF) cout<<-1;
    else cout<<dp[n];
    return 0;
}

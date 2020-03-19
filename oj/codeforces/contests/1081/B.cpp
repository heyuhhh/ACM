#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
const int N = 1e5+5;
int b[N],cnt[N];
int n;
struct node{
    int v,pos;
    bool operator < (const node &A)const{
        return v<A.v;
    }
}a[N];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i].v);
        a[i].pos=i;
    }
    sort(a+1,a+n+1);
    int flag=0;
    a[0].v=-1;a[n+1].v=-1;
    for(int i=1;i<=n;i++){
        int v = a[i].v;
        cnt[v]++;
    }
    for(int i=1;i<=n+1;i++){
        if(a[i].v==a[i-1].v) continue ;
        int need=n-a[i].v;
        if(cnt[a[i].v]%need!=0){
            flag=1;break;
        }
    }
    if(flag){
        printf("Impossible");
    }else{
        int tot=0;
        for(int i=1;i<=n;i++){
            int v=a[i].v;
            int need=n-a[i].v;
            if(cnt[v]%need==0) tot++;
            cnt[v]--;
            b[a[i].pos]=tot;
        }
        printf("Possible\n");
        for(int i=1;i<=n;i++) printf("%d ",b[i]);
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
ll a[N];
int n,m,k;
int vis[N];
struct node{
    ll v,pos;
    bool operator < (const node &A)const{
        return v<A.v;
    }
}b[N];
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        scanf("%I64d",&a[i]);
        b[i]=node{a[i],i};
    }
    sort(b+1,b+n+1);
    ll ans = 0;
    for(int i=n;i>=n-m*k+1;i--){
        ans+=b[i].v;
        vis[b[i].pos]=1;
    }
    int cnt = 0;
    int num=0;
    cout<<ans<<endl;
    for(int i=1;i<=n;i++){
        if(vis[i]){
            cnt++;
            if(cnt==m){
                num++;
                if(num==k) break ;
                cout<<i<<" ";
                cnt=0;
            }
        }
    }
    return 0    ;
}

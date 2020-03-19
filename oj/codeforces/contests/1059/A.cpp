#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int n,L,a;
ll l[N],r[N],vis[N];
int main(){
    cin>>n>>L>>a;
    for(int i=1,x;i<=n;i++){
        scanf("%d%d",&l[i],&x);
        r[i]=l[i]+x;
    }
    int ans = 0;
    sort(l+1,l+n+1);sort(r+1,r+n+1);
    for(int i=1;i<=n;i++){
        int p = lower_bound(r+1,r+n+1,l[i])-r;
        //cout<<p<<endl;
        if(r[p]==l[i]) continue ;
        if(!vis[p-1]){
            int d = l[i]-r[p-1];
            ans+=d/a;
            vis[p-1]=1;
        }
    }
    ans+=(L-r[n])/a;
    cout<<ans;
    return 0;
}

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 200005;
int t;
int a[N],b[N],p[N];
int n;
void solve(){
    int mx=0,id=0;
    memcpy(b,a,sizeof(a));
    a[0]=-1;
    for(int i=1;i<=2*n+1;i++){
        if(i&1) a[i]=0;
        else a[i]=b[i/2];
    }
    //for(int i=1;i<=2*n;i++) cout<<a[i]<<" ";
    //cout<<endl;
    for(int i=2;i<=2*n;i++){
        if(i>=mx) p[i]=1;
        else p[i]=min(mx-i,p[2*id-i]);
        //if(i<mx) continue ;
        while(i-p[i]>=0&&a[i-p[i]]==a[i+p[i]] && ((a[i-p[i]]<=a[i-p[i]+2]&&a[i+p[i]]<=a[i+p[i]-2])||a[i-p[i]]==0)) p[i]++;
        if(p[i]+i>mx){
            mx=p[i]+i;
            id=i;
        }
    }
}
int main(){
    cin>>t;
    while(t--){
        scanf("%d",&n);
        memset(p,0,sizeof(p));
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        solve();
        int ans = 1;
        for(int i=1;i<=2*n;i++){
            ans=max(ans,p[i]-1);
        }
        printf("%d\n",ans);
    }
    return 0;
}

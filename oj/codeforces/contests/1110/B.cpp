#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int N = 1e5+5;
int n,m,k;
ll a[N],d[N];
ll ans;
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++) scanf("%I64d",&a[i]);
    ans=a[n]-a[1]+1;
    priority_queue <ll> q;
    for(int i=1;i<n;i++){
        d[i]=a[i+1]-a[i];
        q.push(d[i]-1);
    }
    int cnt = 1;
    while(cnt<k){
        ll now = q.top();q.pop();
        cnt++;
        ans-=now;
    }
    cout<<ans;
    return 0;
}

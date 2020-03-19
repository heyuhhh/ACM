#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 100005;
int n,m;
int a[N];
ll sum = 0;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i],sum+=a[i];
    sort(a+1,a+n+1);
    int y = 0,x = 0;
    for(int i=1;i<=n;i++){
        x++;
        if(a[i]>y) y++;
    }
    ll ans = 0;
    ans = a[n]-y+x;
    printf("%lld",sum-ans);
    return 0;
}


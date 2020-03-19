#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5,MOD = 1e9+7;
typedef long long ll;
typedef pair<ll ,ll> pll;
int n,x,y;
ll cost[N];
pll a[N];
multiset <ll> s;

int main(){
    scanf("%d%d%d",&n,&x,&y);
    for(int i=1,l,r;i<=n;i++){
        scanf("%I64d%I64d",&a[i].first,&a[i].second);
		s.insert(a[i].second);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        ll l=a[i].first,r=a[i].second;
        cost[i]=(r-l)*y+x;
        if(!s.size() || *s.begin()>=l) continue ;
        multiset <ll>:: iterator it = s.lower_bound(l);
        --it;
        ll pr = *it;
        if((r-pr)*y>=cost[i]) continue ;//中途可能会溢出 
        cost[i]=(r- pr)*y;
        s.erase(it);
    }
    ll ans = 0;
    for(int i=1;i<=n;i++){
        ans+=cost[i];
        ans%=MOD;
    }
    printf("%I64d",ans);
    return 0;
}


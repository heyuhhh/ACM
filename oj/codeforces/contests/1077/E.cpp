#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int a[N],b[N];
int n;
multiset <ll> s;
map <int,int> mp;
int main(){
    scanf("%d",&n);
    int cnt = 0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(!mp[a[i]]) mp[a[i]]=++cnt;
        b[mp[a[i]]]++;
    }
    sort(b+1,b+cnt+1);
    ll ans = 0;
    ll sum;
    int next,Begin;
    for(int i=1;i<=b[cnt];i++){
        ll k = i;
        sum = 0;
        Begin = lower_bound(b+1,b+cnt+1,k)-b;
        while(1){
            if(Begin==cnt+1) break ;
            sum+=k;
            k*=2;
            Begin++;
            next = lower_bound(b+Begin,b+cnt+1,k)-b;
            Begin = next ;
        }
        ans=max(ans,sum);
    }
    cout<<ans;
    return 0;
}

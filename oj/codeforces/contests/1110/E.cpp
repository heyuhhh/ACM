#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
int n;
ll c[N],t[N],d[N];
multiset <ll> s;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    for(int i=1;i<=n;i++) scanf("%d",&t[i]);
    if(c[1]!=t[1] || c[n]!=t[n]){
        cout<<"No";
        return 0;
    }
    for(int i=1;i<n;i++) d[i]=c[i+1]-c[i],s.insert(d[i]);
    for(int i=2;i<=n;i++){
        ll need = t[i]-t[i-1];
        auto it = s.lower_bound(need);
        if(*it==need){
            s.erase(it);
        }else{
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
    return 0;
}

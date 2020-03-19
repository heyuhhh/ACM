#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
ll d[N],a[N];
int n,k;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>k;
    int cnt =0,ans= 0;
    for(int i=1;i<=n;i++){
        cin>>d[i];
        d[i]%=k;
        a[d[i]]++;
    }
    ans+=a[0]/2;
    for(int i=1;i<=k/2;i++){
        if(i*2==k){
            ans+=a[i]/2;
        }else{
            ans+=min(a[i],a[k-i]);
        }
    }
    cout<<ans*2;
    return 0;
}

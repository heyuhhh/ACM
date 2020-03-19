#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5+5;
int n;
int a[N];

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    ll sum=0;
    for(int i=1;i<=n;i++) cin>>a[i],sum+=a[i];
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    int q,qq;
    cin>>q;
    for(int i=1;i<=q;i++){
        cin>>qq;
        cout<<sum-a[qq]<<'\n';
    }
    return 0;
}

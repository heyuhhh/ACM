#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int a[N];
int n,k;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int ans = 0;
    for(int i=1;i<=n;i++){
        int p=upper_bound(a+1,a+n+1,a[i]+5)-a;
        ans=max(ans,p-i);
    }
    cout<<ans;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N  = 3e5+5;
int n,m;
int a[N],b[N];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    cin>>m;
    for(int i=1;i<=m;i++) cin>>b[i];
    int i=1,j=1;
    ll sum1=a[1],sum2=b[1];
    int ans = 0;
    while(i<=n && j<=m){
        if(sum1>sum2){
            j++;
            sum2+=b[j];
        }else if(sum1<sum2){
            i++;
            sum1+=a[i];
        }else {
            ans++;
            i++;j++;
            sum1=a[i];sum2=b[j];
        }
    }
    if(i>n && j>m) cout<<ans;
    else cout<<-1;
    return 0;
}

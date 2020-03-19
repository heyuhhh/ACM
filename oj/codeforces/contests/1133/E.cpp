#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5005;
int n,k;
int a[N];
int dp[N][N],l[N];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        int tmp = lower_bound(a+1,a+n+1,a[i]-5)-a;
        l[i]=tmp-1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            dp[i][j]=dp[i-1][j];
            dp[i][j]=max(dp[i][j],dp[l[i]][j-1]+i-l[i]);
        }
    }
    int ans = 0;
    for(int i=1;i<=k;i++) ans=max(ans,dp[n][i]);
    cout<<ans;
    return 0;
}

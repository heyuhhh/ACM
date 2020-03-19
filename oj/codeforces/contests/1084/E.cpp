#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+5;
ll n,k;
char s[N],t[N];
ll dp[N];
int main(){
    cin>>n>>k;
    scanf("%s%s",s,t);
    dp[0]=1;
    ll ans = 0;
    for(int i=1;i<=n;i++){
        char sc = s[i-1],tc = t[i-1];
        dp[i]=2ll*dp[i-1];
        if(sc=='b') dp[i]--;
        if(tc=='a') dp[i]--;
        if(dp[i]>=k){
            dp[i]=k;
            ans+=(n-i)*k;
            break ;
        }
    }
    for(int i=1;i<=n;i++) if(dp[i]) ans+=dp[i];
    printf("%I64d",ans);
    return 0;
}


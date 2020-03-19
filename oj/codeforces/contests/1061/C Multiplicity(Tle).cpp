#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1000005,MOD = 1e9+7;
ll dp[N];
int n;
int a[N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=sqrt(i);j>=1;j--){
            if(a[i]%j==0){
            	dp[j]+=dp[j-1] , dp[j]%=MOD;
            	if(a[i]/j!=j) dp[a[i]/j]+=dp[a[i]/j-1] ,dp[j]%=MOD; 
			}
        }
    }
    ll sum = 0;
    for(int i=1;i<=n;i++) sum=(sum+dp[i])%MOD;
    printf("%I64d",sum);
    return 0;
}


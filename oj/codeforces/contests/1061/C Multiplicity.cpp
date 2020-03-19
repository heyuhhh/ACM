#include <bits/stdc++.h>
using namespace std;

typedef long long ll ;
const int N = 1000005,MOD = 1e9+7;
ll dp[N];
int n;
int a[N];

int main(){
    scanf("%d",&n);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        vector <int> pos;
        for(int j=1;j*j<=a[i];j++){
            if(a[i]%j==0){
                pos.push_back(j);
                if(a[i]/j!=j) pos.push_back(a[i]/j);
            }
        }
        sort(pos.begin(),pos.end());
        reverse(pos.begin(),pos.end());
        for(int i=0;i<pos.size();i++){
            dp[pos[i]]+=dp[pos[i]-1];
            dp[pos[i]]%=MOD;
        }
    }
    ll ans = 0;
    for(int i=1;i<=n;i++) ans+=dp[i] , ans%=MOD;
    printf("%I64d",ans);
    return 0;
}


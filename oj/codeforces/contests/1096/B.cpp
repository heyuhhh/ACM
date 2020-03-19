#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5,MOD = 998244353;
int n;
char s[N];
int main(){
    scanf("%d",&n);
    scanf("%s",s);
    char fir = s[0];
    int i;
    ll cnt1=1,cnt2=1;
    for(i=1;i<n;i++){
        if(s[i]==fir) cnt1++;
        else break ;
    }
    char last = s[n-1];
    for(i=n-2;i>=0;i--){
        if(s[i]==last) cnt2++;
        else break ;
    }
    ll ans = (cnt1+cnt2+1)%MOD;
    if(last==fir){
        ans=(ans+cnt1*cnt2)%MOD;
    }
    cout<<ans<<endl;
    return 0;
}

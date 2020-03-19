#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 ;
char s[N],t[N];
ll n,k;
int main(){
    cin>>n>>k;
    scanf("%s %s",s,t);
    ll a=0,b=0;
    ll ans =0;
    for(int i=0;i<n;i++){
        ll now;
        a<<=1;b<<=1;
        if(s[i]=='b') a++;
        if(t[i]=='b') b++;
        now = b-a+1;
        if(now>=k){
            ans+=(n-i)*k;
            break ;
        }
        ans+=now;
    }
    printf("%I64d",ans);
    return 0;
}


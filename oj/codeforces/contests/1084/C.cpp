#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5,MOD = 1e9+7;
char s[N];
ll a[N];
int main(){
    scanf("%s",s);
    int len=strlen(s);
    s[len]='b';
    int num=0,cnt=0;
    for(int i=0;i<=len;i++){
        if(s[i]=='a') num++;
        if(s[i]=='b'){
            a[++cnt]=num;
            num=0;
        }
    }
    ll ans = 1;
    for(int i=1;i<=cnt;i++) ans=ans*(a[i]+1)%MOD;
    printf("%I64d",ans-1);
    return 0;
}

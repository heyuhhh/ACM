#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1005;
ll n,k;
int main(){
    cin>>n>>k;
    ll now=k*(k-1);
    if(n>now){
        cout<<"NO";
        return 0;
    }
    puts("YES");
    ll cnt=k-1,num=0,b=1,g=2;
    for(int i=1;i<=n;i+=2){
        if(i!=n) printf("%I64d %I64d\n%I64d %I64d\n",b,g,g,b);
        else printf("%I64d %I64d",b,g);
        num++;
        g++;
        if(num==cnt){
            cnt--;
            b++;
            g=b+1;
            num=0;
        }
    }
    return 0;
}

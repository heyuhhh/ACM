#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans,n,a[105],p[105],base,M;

const char *definitely_lie = "he was definitely lying";
const char *probably_lie = "he was probably lying";

int main(){
    cin >> n >> M;
    for (int i=0;i<n;i++) cin >> p[i] >> a[i];
    for (int i=0;i<n;i++)
    for (int j=i+1;j<n;j++){
        ll d=__gcd(p[i],p[j]);
        if (d!=1){
            if (a[i]%d!=a[j]%d){
                puts(definitely_lie);
                return 0;
            }
        }
    }
    ans=0; base=1;
    for (int i=0;i<n;i++){
        while (ans%p[i]!=a[i]) {
            ans+=base;
            if (ans>M){
                puts(probably_lie);
                return 0;
            }
        }
        ll gg=p[i]/__gcd(base,p[i]);
        if (M/base>=gg) base*=gg;
        else {
            for (int j=i+1;j<n;j++) if (ans%p[j]!=a[j]){
                puts(probably_lie);
                return 0;
            }
            printf("%lld\n",ans);
            return 0;
        }
    }
    for (int i=0; i<n; i++) assert(ans % p[i] == a[i]);
    printf("%lld\n",ans);
    return 0;
}

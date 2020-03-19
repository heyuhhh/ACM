#include <bits/stdc++.h>
using namespace std;

typedef long long ll ;

ll pathl(ll n,ll k){
    k--;
    ll pow2 = 4,cnt = 0;
    while(k>=pow2-1){
         cnt++;
        k-=(pow2-1);
        pow2*=2;
    }
    return max(n-1-cnt,(ll)0);
}
int main(){
    ll t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        if(n==2 && k==3){
            puts("NO");continue ;
        }
        ll pow4=1,tmp1=k,tmp2=n;
        if(n<=35){
            while(tmp2--){
                tmp1-=pow4;
                pow4*=4;
            }
            if(tmp1>0){
                puts("NO");continue;
            }
            printf("YES %d\n",pathl(n,k));
        }else{
            printf("YES %d\n",pathl(n,k));
        }
    }

    return 0;
}


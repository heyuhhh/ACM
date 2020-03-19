#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 10;
int T;
ll l,r;
int main(){
    cin>>T;
    while(T--){
        scanf("%I64d%I64d",&l,&r);
        for(ll i=l;i<=r;i++){
            if(i*2<=r){
                printf("%I64d %I64d\n",i,2*i);
                break ;
            }
        }

    }
    return 0;
}

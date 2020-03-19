#include <bits/stdc++.h>
#define Max 100000
using namespace std;
typedef long long ll;
const int N = 2e5+5;
ll sum[N];
int main(){
    sum[1]=2;
    for(int i=2;i<=1e5;i++){
        sum[i]=sum[i-1]+2*i;
    }
    ll n;
    cin>>n;
    int pos=lower_bound(sum+1,sum+Max+1,n)-sum;
    pos--;
    if(sum[pos]+pos+1>=n){
        cout<<2*pos+2;
    }else{
        cout<<2*pos+3;
    }
    return 0;
}

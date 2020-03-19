#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int n;
int b,k;
int a[N];
ll qp(ll A,ll B){
    ll ans = 1;
    while(B){
        if(B&1) ans=ans*A%2;
        A=A*A%2;
        B>>=1;
    }
    return ans;
}
int main(){
    cin>>b>>k;
    for(int i=1;i<=k;i++) scanf("%d",&a[i]);
    int t=b%2;
    int sum = 0;
    for(int i=k-1;i>=0;i--){
        sum=sum+a[k-i]*qp(t,i);
        sum%=2;
    }
    if(sum&1) cout<<"odd";
    else cout<<"even";
    return 0;
}

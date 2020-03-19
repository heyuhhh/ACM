#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int k,v,a,b;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>k;
    int n=2000;
    v=1;
    while(1){
        int f1=0,f2=0;
        if((k+v)%n==0) f1=1;
        if(f1&&(k+v)/n-v<0) f2=1;
        if(f1&&f2) break ;
        v++;
    }
    a=v;
    b=(k+v)/n-a;
    cout<<n<<endl;
    for(int i=1;i<=n-2;i++) cout<<0<<" ";
    cout<<b<<" "<<a;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 4e5+5;
int n;
ll a[N],b[N];
int main(){
    cin>>n;
    for(int i=1;i<=n/2;i++) cin>>b[i];
    a[1]=0;a[n]=b[1];
    for(int i=2;i<=n/2;i++){
        ll d = b[i]-b[i-1];
        if(d>=0) a[i]=d+a[i-1],a[n-i+1]=a[n-i+2];
        else a[i]=a[i-1],a[n-i+1]=a[n-i+2]+d;
    }
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    return 0;
}

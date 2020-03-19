#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 105;
int a[N],ans[N];
int n;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int fir=1,last=n;
    for(int i=1;i<=n;i++){
        if(i&1){
            ans[fir++]=a[i];
        }else ans[last--]=a[i];
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    return 0;
}

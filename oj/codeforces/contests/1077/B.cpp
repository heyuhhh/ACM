#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 105;
int n;
int a[N];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int ans = 0;
    for(int i=2;i<n;i++){
        if(a[i]==0 && a[i-1] && a[i+1]){
            a[i+1]=0;
            ans++;
        }
    }
    cout<<ans;
    return 0;
}

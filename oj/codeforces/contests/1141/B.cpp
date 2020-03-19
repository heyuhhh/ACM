#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int n;
int a[N];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int fir = 0,sec = 0,f= 0;
    for(int i=1;i<=n;i++){
        if(a[i]==1) fir++;
        else break ;
    }
    for(int j=n;j>=1;j--){
        if(a[j]==1) sec++;
        else break ;
    }
    int ans = fir+sec;
    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(a[i]==1){
            cnt++;
            ans=max(ans,cnt);
        }else cnt =0;
    }
    cout<<ans;
    return 0;
}

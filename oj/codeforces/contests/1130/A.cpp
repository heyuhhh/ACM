#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n;
double a[N];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    int cnt1 = 0,cnt2=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>0) cnt1++;
        else if(a[i]<0) cnt2++;
    }
    if(cnt1>=(n+1)/2) cout<<1;
    else if(cnt2>=(n+1)/2) cout<<-1;
    else cout<<0;
    return 0;
}

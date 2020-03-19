#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
const int N = 2e5+5;
int a[N];
int n;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int b=0,c=0,d=0;
    int ans =0;
    if(a[1]==2) b++;
    else c++;
    if(a[n]==1) a[n+1]=2;
    else a[n+1]=1;
    for(int i=2;i<=n+1;i++){
        if(a[i]==a[i-1]&&a[i]==2){
            b++;
        }else if(a[i]==a[i-1]&&a[i]==1){
            c++;
        }else{
            if(a[i]==2){
                ans=max(ans,2*min(c,b));
                b=1;
            }else{
                ans=max(ans,2*min(c,b));
                c=1;
            }
        }
    }
    cout<<ans;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int n,k;
int a[N];
int main(){
    cin>>n>>k;
    int ans=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    int sum1=0,sum2=0;
    for(int i=1;i<=n;i++){if(a[i]==1) sum1++;else sum2++;}
    for(int b=1;b<=k;b++){
        int now1=sum1,now2=sum2;
        for(int i=b;i<=n;i+=k){
            if(a[i]==1) now1--;
            else now2--;
        }
        ans=max(ans,abs(now1-now2));
    }
    cout<<ans;
    return 0;
}

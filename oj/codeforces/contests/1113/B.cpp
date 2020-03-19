#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
int a[N];
int n;
int main(){
    scanf("%d",&n);
    int sum = 0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    int ans = sum;
    int mn = *min_element(a+1,a+n+1);
    sum-=mn;
    for(int i=1;i<=n;i++){
        for(int j=2;j<=a[i];j++){
            if(a[i]%j!=0) continue ;
            ans=min(ans,sum-a[i]+a[i]/j+mn*j);
        }
    }
    cout<<ans;
    return 0;
}

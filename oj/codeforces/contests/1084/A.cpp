#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int a[N];
int n;

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int ans = 99999999;
    for(int x=1;x<=n;x++){
        int sum = 0;
        for(int i=1;i<=n;i++)
            sum+=(abs(x-i)+i+x-2)*a[i]*2;
        ans=min(ans,sum);
    }
    printf("%d",ans);
    return 0;
}

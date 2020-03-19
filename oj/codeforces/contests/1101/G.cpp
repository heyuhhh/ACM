#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int a[N],p[N],sum[N];
int n;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum[i]=sum[i-1]^a[i];
    }
    if(!sum[n]){
        cout<<-1;
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=29;j>=0;j--){
            if(!((1<<j)&sum[i])) continue ;
            if(!p[j]){
                p[j]=sum[i];
                break ;
            }
            sum[i]^=p[j];
        }
    }
    int ans = 0;
    for(int i=0;i<30;i++) if(p[i]) ans++;
    cout<<ans;
    return 0;
}


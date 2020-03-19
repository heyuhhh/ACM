#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5005;
int n,k;
int a[N],cnt[N],ans[N];
int main(){
    cin>>n>>k;
    int ok = 0,mx = 0,v,tot;
    if(n<k) ok=1;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        cnt[a[i]]++;
        if(cnt[a[i]]>mx){
            mx = cnt[a[i]];
            v = a[i];
        }
        if(cnt[a[i]]>k) ok =1;
        ans[i]=cnt[a[i]];
    }
    tot = k-mx;
    if(ok) cout<<"NO";
    else{
        puts("YES");
        for(int i=1;i<=n;i++){
            if(a[i]==v) cout<<ans[i]<<" ";
            else{
                if(tot<=0) cout<<ans[i]<<" ";
                else{
                    cout<<mx+tot<<" ";
                    tot--;
                }
            }
        }
    }
    return 0;
}

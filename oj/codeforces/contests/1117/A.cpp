#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int n;
int a[N];
int main(){
    cin>>n;
    int cnt=1,ans=1;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int mx=*max_element(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        if(a[i]==mx && a[i-1]==mx){
            cnt++;
        }else{
            ans=max(ans,cnt);
            cnt=1;
        }
    }
    cout<<max(ans,cnt);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int n;
ll sum[N];
struct node{
    int v,id;
    bool operator < (const node &A)const{
        return v<A.v;
    }
}a[N];
int main(){
    scanf("%d",&n);
    for(int i=1,p;i<=n;i++){
        scanf("%d",&p);
        a[i]={p,i};
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i].v;
    vector <int> ans;
    for(int i=n;i>=1;i--){
        if(i==n){
            if(sum[i-2]==a[i-1].v) ans.push_back(a[i].id);
        }else{
            if(sum[n-1]-a[i].v==a[n].v) ans.push_back(a[i].id);
        }
    }
    cout<<ans.size()<<endl;
    for(auto v:ans) cout<<v<<" ";
    return 0;
}

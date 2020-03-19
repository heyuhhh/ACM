#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int n,k;
int s[N],cnt[N];
vector <int> ans;
bool check(int x){
    ans.clear();
    for(int i=1;i<=N-5;i++){
        if(!cnt[i]) continue ;
        int need = min(cnt[i]/x,k-int(ans.size()));
        for(int j=1;j<=need;j++) ans.push_back(i);
        if(ans.size()==k) return true;
    }
    return false;
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&s[i]);
        cnt[s[i]]++;
    }
    int l=1,r=N,mid;
    int re;
    while(l<r){
        mid=l+r>>1;
        if(check(mid)){
            l=mid+1;
            re=mid;
        }else r=mid;
    }
    check(re);
    for(auto v:ans) printf("%d ",v);
    return 0;
}

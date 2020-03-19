#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5 ;
int n;
int a[N];
vector <pair<pair<int,int>,int> > ans;
int main(){
    scanf("%d",&n);
    a[0]=-1;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int sum=0;
    for(int i=n;i>=1;i--){
        a[i]+=sum;
        if(a[i]%n!=i-1){
            int tmp = i-1-a[i]%n;
            while(tmp<n) tmp+=n;
            ans.push_back({{1,i},tmp});
            sum+=tmp;
        }else ans.push_back({{1,i},0});
    }
    ans.push_back({{2,n},n});
    cout<<ans.size()<<endl;
    for(auto v : ans){
        cout<<v.first.first<<" "<<v.first.second<<" "<<v.second<<endl;
    }
    return 0;
}

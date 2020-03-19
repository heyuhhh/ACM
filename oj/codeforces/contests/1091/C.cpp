#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
vector <ll> vec;
int main(){
    cin>>n;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            vec.push_back(i);
            if(i*i!=n) vec.push_back(n/i);
        }
    }
    vec.push_back(1);vec.push_back(n);
    vector <ll > ans ;
    for(auto d:vec){
        ll last = n-d+1;
        ans.push_back((last+1)*((last-1)/d+1)/2);
    }
    sort(ans.begin(),ans.end());
    for(auto v:ans){
        printf("%I64d ",v);
    }
    return 0;
}

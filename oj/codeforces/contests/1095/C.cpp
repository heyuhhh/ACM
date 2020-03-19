#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;
multiset <int> s;
int main(){
    cin>>n>>k;
    for(int i=30;i>=0;i--){
        if(n&(1<<i)) s.insert(i);
    }
    int len = s.size();
    if(n<k || len>k){
        puts("NO");
        return 0;
    }
    puts("YES");
    while(s.size()<k){
        auto it = s.end();
        it--;
        int now=*it;
        s.erase(it);
        s.insert(now-1);
        s.insert(now-1);
    }
    for(auto x:s)
        cout<<(1<<x)<<" ";
    return 0;
}

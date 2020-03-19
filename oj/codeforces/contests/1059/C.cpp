#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector <int> ans;
void solve(int x,int y){
    if(x==1){
        ans.push_back(y);return ;
    }
    if(x==2){
        ans.push_back(y);ans.push_back(2*y);return ;
    }
    if(x==3){
        ans.push_back(y);ans.push_back(y);ans.push_back(3*y);return ;
    }
    int tmp=x;
    for(int i=1;i<=x;i+=2) ans.push_back(y),tmp--;
    solve(tmp,2*y);
}
int main(){
    cin>>n;
    solve(n,1);
    for(auto v:ans) cout<< v<<" ";
    return 0;
}

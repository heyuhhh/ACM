#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
ll n,k;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>k;
    cout<<k/n+(k%n!=0);
    return 0;
}

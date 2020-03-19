#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int n,k;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>k;
    cout<<n + n+1 + n-1+min(n-k,k-1);
    //捡硬币，扔石头，和移动 
	return 0;
}


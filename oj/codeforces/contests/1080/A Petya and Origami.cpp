#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;
ll n,k;

int main(){
	cin>>n>>k;
	ll r = 2*n,g = 5*n,b = 8*n;
	ll ans = r/k+(r%k!=0)+g/k+(g%k!=0)+b/k+(b%k!=0);
	cout<<ans;
} 

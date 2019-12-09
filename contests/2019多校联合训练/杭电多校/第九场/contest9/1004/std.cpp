#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <unordered_map>
#include <algorithm>
using namespace std;
long long n;
const int mo=998244353;
const int N=40000000;
int phi[N+10],prime[5000000],len,s[N+10];
unordered_map<long long,int>M;
long long get(long long n){
	n%=mo;
	return n*(n+1)/2;
}
int gets(long long K){
	if (K<=N) return s[K];
	if (M[K]) return M[K]-1;
	int ans=get(K)%mo;
	for (long long i=2,ne;i<=K;i=ne+1){
		ne=K/(K/i);
		ans=(ans-(ne-i+1)%mo*gets(K/i))%mo;
	}
	ans=(ans+mo)%mo;
	M[K]=ans+1; return ans;
}
int getsqrt(long long k){
	int num=sqrt(k);
	while (1ll*num*num<k) num++;
	while (1ll*num*num>k) num--;
	return num;
}
void solve(){
	scanf("%lld",&n);
	int ans=n%mo;
	ans=(1ll*ans*(ans+1)/2)%mo;
	for (int now=2;;++now){
		long long cur=1ll*now*now;
		if (cur>n/now) break;
		cur*=now;
		while (1){
			ans=(ans+n/cur%mo*phi[now])%mo;
			if (cur>n/now) break;
			cur*=now;
		}
	}
	for (long long i=2,ne=0;1ll*i*i<=n;i=ne+1){
		ne=getsqrt(n/(n/i/i)); 
		ans=(ans+n/i/i%mo*(gets(ne)-gets(i-1)+mo)%mo)%mo;
	}
	printf("%d\n",ans);
}
int main(){
	len=0; phi[1]=1;
	for (int i=2;i<=N;i++){
		if (phi[i]==0){
			prime[++len]=i; phi[i]=i-1;
		}
		for (int j=1;j<=len&&prime[j]*i<=N;j++){
			if (i%prime[j]==0){
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			} else {
				phi[i*prime[j]]=phi[i]*(prime[j]-1);
			}
		}
	}
	for (int i=1;i<=N;i++) s[i]=(s[i-1]+phi[i])%mo;
	int t; scanf("%d",&t);
	for (;t;t--) solve();
}
#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cassert>
#include <map>
#include <vector>
using namespace std;
int n,m;
long long K;
const int N=110000;
vector<int> A[3],B[3];
long long get(long long lim){
	if (lim>=0){
		long long ans=(long long)(A[1].size())*m+(long long)(B[1].size())*(n-A[1].size());
		ans+=1ll*A[0].size()*B[2].size()+1ll*A[2].size()*B[0].size();
		for (int a=0;a<=2;a+=2){
			int b=a;
			int now=int(B[b].size())-1;
			for (int i=0;i<A[a].size();++i){
				while (now>=0&&1ll*A[a][i]*B[b][now]>lim) now--;
				ans+=now+1;
			}
		}
		return ans;
	} else if (lim<0){
		long long ans=0; lim=-lim;
		for (int a=0;a<=2;a+=2){
			int b=2-a;
			int now=int(B[b].size())-1;
			for (int i=0;i<A[a].size();++i){
				while (now>=0&&1ll*A[a][i]*B[b][now]>=lim) now--;
				ans+=int(B[b].size())-now-1;
			}
		}
		return ans;
	}
}
int main(){
	scanf("%d%d%lld",&n,&m,&K);
	K=1ll*n*m-K+1;
	for (int i=1;i<=n;i++){
		int k1; scanf("%d",&k1);
		if (k1>0) A[0].push_back(k1);
		else if (k1==0) A[1].push_back(k1);
		else A[2].push_back(-k1);
	}
	for (int i=1;i<=m;i++){
		int k1; scanf("%d",&k1);
		if (k1>0) B[0].push_back(k1);
		else if (k1==0) B[1].push_back(k1);
		else B[2].push_back(-k1);
	}
	for (int i=0;i<3;i++){
		sort(A[i].begin(),A[i].end());
		sort(B[i].begin(),B[i].end());
	}
	long long l=0,r=2e18,ans=0,bias=1e18;
	while (l<r){
		long long mid=(l+r>>1);
		if (get(mid-bias)>=K){
			ans=mid-bias; r=mid;
		} else l=mid+1;
	}
	cout<<ans<<endl;
}
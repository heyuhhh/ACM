#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
const int N=50;
int n,w[N];
struct atom{
	long long l,r;
};
vector<atom>x,y,A[10],B[10];
void solve(int k1,int lim,long long sum,vector<atom>&x){
	if (k1>lim){
		x.push_back((atom){sum,0}); return;
	}
	solve(k1+1,lim,sum,x);
	solve(k1+1,lim,sum+w[k1],x);
}
long long get0(vector<atom>&A,vector<atom>&B,long long lim){
	int now=B.size()-1;
	long long ans=0;
	for (int i=0;i<A.size();i++){
		while (now>=0&&B[now].r+A[i].r>=lim) now--;
		ans+=now+1;
	}
	return ans;
}
long long get1(vector<atom>&A,vector<atom>&B,long long lim){
	int now=0;
	long long ans=0;
	for (int i=A.size();i;i--){
		while (now<B.size()&&B[now].r+A[i-1].r<lim) now++;
		ans+=B.size()-now;
	}
	return ans;
}
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&w[i]);
	//n=40;
	//for (int i=1;i<=n;i++) w[i]=rand()%1000000000+1;
	int mid=n/2; x.clear(); y.clear();
	solve(1,mid,0,x);
	solve(mid+1,n,0,y);
	long long ans=0;
	long long base=1;
	for (int t=1;t<=12;t++){
		for (int i=0;i<10;i++) A[i].clear(),B[i].clear();
		for (int i=0;i<x.size();i++) A[x[i].l%10].push_back((atom){x[i].l/10,x[i].r});
		for (int i=0;i<y.size();i++) B[y[i].l%10].push_back((atom){y[i].l/10,y[i].r});

		for (int i=0;i<10;i++){
			int k1=(14-i)%10,k2=(13-i)%10;
			ans+=get0(A[i],B[k1],base)+get1(A[i],B[k2],base);
		}
		int now=0;
		for (int i=0;i<10;i++){
			long long ex=i*base;
			for (int j=0;j<A[i].size();j++)
				x[now++]=(atom){A[i][j].l,A[i][j].r+ex};
		}
		now=0;
		for (int i=0;i<10;i++){
			long long ex=i*base;
			for (int j=0;j<B[i].size();j++)
				y[now++]=(atom){B[i][j].l,B[i][j].r+ex};
		}
		base*=10;
	}
	printf("%lld\n",ans);
}
int main(){
	int t; scanf("%d",&t);
	for (;t;t--) solve();
	return 0;
}
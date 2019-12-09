#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
//#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head
 
void gao(ll pa,ll pb,ll qa,ll qb,ll &x,ll &y) {
	ll z=(pa+pb-1)/pb;
	if (z<=qa/qb) {
		x=z; y=1;
		return;
	}
	pa-=(z-1)*pb; qa-=(z-1)*qb;
//	printf("ff %lld %lld %lld %lld\n",pa,pb,qa,qb);
	gao(qb,qa,pb,pa,y,x);
	x+=(z-1)*y;
}
int _;
ll a,p,x,y;
 
int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%lld%lld",&p,&a);
		gao(p,a,p,a-1,x,y);
		ll z=x*a-p*y;
		printf("%lld/%lld\n",z,x);
//		printf("%lld %lld\n",x,y);
	}
}


#include "bits/stdc++.h"
#define hhh cerr<<"hhh"<<endl
#define see(x) cerr<<(#x)<<'='<<(x)<<endl
using namespace std;
typedef unsigned int ll;
typedef pair<int,int> pr;
inline int read() {int x=0,f=1;char c=getchar();while(c!='-'&&(c<'0'||c>'9'))c=getchar();if(c=='-')f=-1,c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return f*x;}
 
const int maxn = 1e7+7;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
 
int n, m;
ll A, B, C, x, y, z;
ll a[maxn];
struct node {
    int val;
    int p;
    bool operator < (const node& A) const {
        return val < A.val;   
    }
}b[105];
ll ans[maxn];
 
ll rng61() {
	ll t;
	x = x ^ (x << 16);
	x = x ^ (x >> 5);
	x = x ^ (x << 1);
	t = x;
	x = y;
	y = z;
	z = (t ^ x) ^ y;
	return z;
}
 

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int cas=0;
    while(cin>>n>>m>>A>>B>>C) {
        x=A, y=B, z=C;
        for(int i=0; i<n; ++i) {
            a[i]=rng61();
        }
        cout<<"Case #"<<++cas<<':';
        for(int i=0; i<m; ++i) {
            cin>>b[i].val;
            b[i].p = i;
        }   
        sort(b, b+m);
        int r=n;
        for(int i=m-1; i>=0; --i) {
            nth_element(a,a+b[i].val,a+r);
            ans[b[i].p]=a[b[i].val];
            r=b[i].val;
        }
        for(int i=0; i<m; ++i) cout<<' '<<ans[i];
        cout<<'\n';
    }
}

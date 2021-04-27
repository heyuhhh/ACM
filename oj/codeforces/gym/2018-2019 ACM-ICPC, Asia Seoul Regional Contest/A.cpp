#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef pair<int,int> pii;
#define MAXN (int(1e5)+7)
pii seq[MAXN];
int pos[MAXN*2];
int ans1[MAXN];
struct node {
	int dt; int down;
} segtree[MAXN<<3];
int L, R, X;
inline void build(int p, int l, int r) {
	segtree[p].dt=segtree[p].down=0;
	if(l==r) return;
	int m=(l+r)/2;
	build(p*2,l,m);
	build(p*2+1,m+1,r);
}
inline void pd(int p, int l, int r) {
	if(l!=r) {
		segtree[p*2].dt+=segtree[p].down;
		segtree[p*2].down+=segtree[p].down;
		segtree[p*2+1].dt+=segtree[p].down;
		segtree[p*2+1].down+=segtree[p].down;
	}
	segtree[p].down=0;
}
inline void opa(int p,int l, int r) {
	pd(p,l,r);
	if(l>=L && r<=R) {
		segtree[p].dt+=X;
		segtree[p].down+=X;
		return;
	}
	int m=(l+r)/2;
	if(m>=L) opa(p*2, l,m);
	if(m<R) opa(p*2+1, m+1, r);
	segtree[p].dt=max(segtree[p*2].dt, segtree[p*2+1].dt);
}
inline int opq(int p, int l, int r) {
	pd(p,l,r);
	if(l>=L && r<=R) {
		return segtree[p].dt;
	}
	int m=(l+r)/2;
	int ans=-1;
	if(m>=L) ans=max(ans,opq(p*2,l,m));
	if(m<R) ans=max(ans,opq(p*2+1, m+1,r));
	return ans;
}
inline int opq2(int p, int l, int r) {
	pd(p,l,r);
	if(l==L) {
		return segtree[p].dt;
	}
	int m=(l+r)/2;
	if(m>=L) return opq2(p*2,l,m);
	else return opq2(p*2+1,m+1,r);
}
int main() {
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	#endif
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	
	for(int i=0; i<n; i++) {
		int a,b,c,d; cin >> a >> b >> c >> d;
		seq[i]=pii(b,d);
		pos[i*2]=b; pos[i*2+1]=d;
	}
	sort(pos,pos+n+n);
	int posn=unique(pos,pos+n+n)-pos;
	sort(seq,seq+n,greater<pii>());
	
	build(1,0,posn);
	
	X=1;
	for(int i=0; i<n; i++) {
		seq[i].first=lower_bound(pos,pos+posn,seq[i].first)-pos;
		seq[i].second=lower_bound(pos,pos+posn,seq[i].second)-pos;
		
		R=seq[i].first, L=seq[i].second;
		opa(1,0,posn);
	}
	for(int i=0; i<n; i++) {
		L=seq[i].first;
		ans1[i]=opq2(1,0,posn);
	}
	
	int ans=0;
	
	X=-1;
	for(int i=0; i<n; ) {
		pii now = seq[i++];
		
		R=now.first, L=now.second;
		opa(1,0,posn);
		
		while(i<n && seq[i].first==now.first) {
			R=seq[i].first, L=seq[i].second;
			opa(1,0,posn);
			i++;
		}
		
		L=0, R=posn;
		ans = max(ans, ans1[i-1]+opq(1,0,posn));
	}
	cout << ans << '\n';
	
}

#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MO=int(1e9)+7;

int a,b,c,A,B,C;

//0<z<l
inline bool calc(int A, int B, int C, int x, int y, int l, int &ansl, int &ansr) {
	if(C==0) return false;
	int L,R;
	if(C<0) {
		L=0, R=l*(-C);
	} else {
		L=l*(-C), R=0;
	}
	L-=A*x+B*y, R-=A*x+B*y;
	ansl=L, ansr=R;
	//cerr << L << ' ' << R << '\n';
	return true;
}

pii seg[17]; int segn;
pii win[40]; int winn;
int len[4];
inline int qpow(int a, int b) {
	int ans=1;
	for(;b;b>>=1) {
		if(b&1) ans=1ll*ans*a%MO;
		a=1ll*a*a%MO;
	}
	return ans;
}
void run() {
	segn=0;
	memset(len,0,sizeof len);
	cin >> a >> b >> c >> A >> B >> C;
	int L,R;
	if(calc(B,C,(A),b,c,(a),L,R)) {seg[segn].first=L, seg[segn].second=R; segn++;}
	if(calc(B,C,(A),0,c,(a),L,R)) {seg[segn].first=L, seg[segn].second=R; segn++;}
	if(calc(B,C,(A),0,0,(a),L,R)) {seg[segn].first=L, seg[segn].second=R; segn++;}
	if(calc(B,C,(A),b,0,(a),L,R)) {seg[segn].first=L, seg[segn].second=R; segn++;}
	
	if(calc(A,C,(B),a,c,(b),L,R)) {seg[segn].first=L, seg[segn].second=R; segn++;}
	if(calc(A,C,(B),a,0,(b),L,R)) {seg[segn].first=L, seg[segn].second=R; segn++;}
	if(calc(A,C,(B),0,0,(b),L,R)) {seg[segn].first=L, seg[segn].second=R; segn++;}
	if(calc(A,C,(B),0,c,(b),L,R)) {seg[segn].first=L, seg[segn].second=R; segn++;}
	
	if(calc(A,B,(C),a,b,(c),L,R)) {seg[segn].first=L, seg[segn].second=R; segn++;}
	if(calc(A,B,(C),a,0,(c),L,R)) {seg[segn].first=L, seg[segn].second=R; segn++;}
	if(calc(A,B,(C),0,0,(c),L,R)) {seg[segn].first=L, seg[segn].second=R; segn++;}
	if(calc(A,B,(C),0,b,(c),L,R)) {seg[segn].first=L, seg[segn].second=R; segn++;}
	
	for(int i=0; i<segn; i++) {
		win[i*2].second=0;
		win[i*2].first=seg[i].first;
		win[i*2+1].second=1;
		win[i*2+1].first=seg[i].second;
	}
	segn*=2;
	sort(win,win+segn);
	int cnt=0;
	for(int i=0; i<segn; i++) {
		if(cnt>=3 && cnt<=6) {
		//	if(seg[i].first==0) {
				len[cnt-3]=((len[cnt-3]+
					win[i].first-win[i-1].first)%MO+MO)%MO;
		
		}
		if(win[i].second==0) {
			cnt++;
		} else {
			cnt--;
		}
	}
	//cout << len[0] << ' ' << len[1] << ' ' << len[2] << ' ' << len[3] << '\n';
	int s=(len[0]+len[1])%MO+(len[2]+len[3])%MO;
	int s_1=qpow(s,MO-2);
	int ans[4];
	ans[0]=1ll*len[0]*s_1%MO;
	ans[1]=1ll*len[1]*s_1%MO;
	ans[2]=1ll*len[2]*s_1%MO;
	ans[3]=1ll*len[3]*s_1%MO;
	cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << ' ' << ans[3] << '\n';
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(20);
	int T; cin >> T; while (T--)
	run();
	return 0;
}


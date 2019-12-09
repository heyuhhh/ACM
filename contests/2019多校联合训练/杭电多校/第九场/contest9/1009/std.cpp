#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
const int N=5100;
struct point{
	int x;
	long long y;
	point operator - (point k1){return (point){x-k1.x,y-k1.y};}
}s[N];
long long cross(point k1,point k2){
	return k1.x*k2.y-k1.y*k2.x;
}
struct atom{
	int type,t,en,L,R;
}x[N],y[N];
struct atom2{
	int r,L,R,type;
	long long f;
}z[N];
int n,T[2],c[N][2],m;
long long dp[N],f[N],tot[N][2];
int compare1(atom k1,atom k2){
	return k1.t<k2.t;
}
int compare2(atom k1,atom k2){
	return k1.en<k2.en;
}
long long getcost(int l,int r,int type,int t){
	return 1ll*(c[r][type]-c[l][type])*t-(tot[r][type]-tot[l][type]);
}
int maxs=0;
void solve(){
	scanf("%d%d%d",&n,&T[0],&T[1]);
	for (int i=1;i<=n;i++){
		scanf("%d%d",&x[i].type,&x[i].t); x[i].type--;
		x[i].en=x[i].t+T[x[i].type];
	}
	sort(x+1,x+n+1,compare1);
	for (int i=1;i<=n;i++) y[i]=x[i];
	int now=1;
	for (int i=1;i<=n;i++){
		while (now<=n&&y[now].t<=x[i].t) now++;
		x[i].L=now-1;
	}
	sort(x+1,x+n+1,compare2);
	now=1;
	for (int i=1;i<=n;i++){
		while (now<=n&&y[now].t<=x[i].en) now++;
		x[i].R=now-1;
	}
	for (int i=1;i<=n;i++){
		memcpy(c[i],c[i-1],sizeof c[i-1]);
		memcpy(tot[i],tot[i-1],sizeof tot[i-1]);
		c[i][y[i].type]++;
		tot[i][y[i].type]+=y[i].t;
	}
	//cout<<"array"<<endl;
	//for (int i=1;i<=n;i++) cout<<c[i][0]<<" "<<c[i][1]<<" "<<tot[i][0]<<" "<<tot[i][1]<<endl;
	for (int i=1;i<=n;i++) dp[i]=getcost(0,x[i].R,x[i].type^1,x[i].en);
	//for (int i=1;i<=n;i++) cout<<dp[i]<<" "; cout<<endl;
	long long ans=1e18;
	for (int ss=1;ss<=n;ss++){
		m=1; z[1].r=x[ss].en; z[1].L=x[ss].L; z[1].R=x[ss].R; z[1].type=x[ss].type;
		z[0].L=0; z[0].type=z[1].type^1; 
		while (m==1||c[z[m].R][z[m-1].type]!=c[z[m-1].L][z[m-1].type]){
			m++; z[m].L=z[m-1].R; z[m].type=z[m-1].type^1; z[m].R=z[m].L; z[m].r=z[m-1].r+T[z[m].type];
			while (z[m].R<=n&&y[z[m].R].t<=z[m].r) z[m].R++; z[m].R--;
		}
		z[1].f=dp[ss];
		for (int i=2;i<=m;i++){
			z[i].f=z[i-1].f+getcost(z[i-1].L,z[i].R,z[i-1].type,z[i].r);
			if (c[z[i].L][z[i].type]==c[n][z[i].type]){
				ans=min(ans,z[i].f);
			}
		}
		/*for (int ty=0;ty<2;ty++)
			for (int i=1;i<=m;i++)
				for (int j=ss+1;j<=n;j++)
					if (z[i].type!=ty&&x[j].type==ty&&x[j].t>=z[i].r){
						dp[j]=min(dp[j],z[i].f+getcost(z[i].L,x[j].R,z[i].type,x[j].en));
					}*/
		//for (int i=1;i<=n;i++) cout<<dp[i]<<" "; cout<<endl;
		for (int ty=0;ty<2;ty++){
			int cur=1,head=0,now=1;
			for (int i=ss+1;i<=n;i++){
				if (x[i].type!=ty) continue;
				while (cur<=m&&z[cur].r<=x[i].t){
					if (z[cur].type!=ty){
						point curp=(point){c[z[cur].L][z[cur].type],z[cur].f+tot[z[cur].L][z[cur].type]};
						while (head>now&&cross(s[head]-s[head-1],curp-s[head])<=0) head--;
						s[++head]=curp;
					}
					cur++;
				}
				maxs=max(maxs,head-now);
				while (now<head&&s[now+1].y-s[now].y<=1ll*(s[now+1].x-s[now].x)*x[i].en) now++;
				if (now<=head){
					dp[i]=min(dp[i],s[now].y+1ll*(c[x[i].R][ty^1]-s[now].x)*x[i].en-tot[x[i].R][ty^1]);
				}
			}
		}
	}
	//for (int i=1;i<=n;i++) cout<<x[i].t<<" "<<x[i].en<<" "<<x[i].L<<" "<<x[i].R<<endl;
	//for (int i=1;i<=n;i++) cout<<dp[i]<<" "; cout<<endl;
	for (int i=1;i<=n;i++) if (c[x[i].L][x[i].type]==c[n][x[i].type]) ans=min(ans,dp[i]);
	printf("%lld\n",ans);
}
int main(){
	int t; scanf("%d",&t);
	for (;t;t--) solve();
	return 0;
}
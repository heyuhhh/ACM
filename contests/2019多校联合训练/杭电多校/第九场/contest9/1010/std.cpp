#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cassert>
#include <queue>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
int n,K;
const int N=110000,MK=52;
struct point{
	int x,y,pos;
	point operator - (point k1){return (point){x-k1.x,y-k1.y};}
	point operator + (point k1){return (point){x+k1.x,y+k1.y};}
	int operator < (const point k1) const {return x<k1.x||(x==k1.x&&y<k1.y);}
	void scan(){scanf("%d%d",&x,&y);}
	void print(){printf("%d %d %d\n",x,y,pos);}
}p[N],o;
const int mo=10000019;
int fir[mo],ne[N*MK],hashlen,ans[N],tag[mo],hashsign,m;
long long w[N*MK];
void put(int u,int v){
	if (u>v) swap(u,v);
	long long k1=1ll*u*n+v; int k2=k1%mo;
	if (tag[k2]!=hashsign){
		tag[k2]=hashsign; fir[k2]=0;
	}
	for (int i=fir[k2];i;i=ne[i])
		if (w[i]==k1) return;
	hashlen++; w[hashlen]=k1; ne[hashlen]=fir[k2]; fir[k2]=hashlen;
	//cout<<"put "<<u<<" "<<v<<endl;
	ans[u]++; ans[v]++;
}
long long cross(point k1,point k2){
	return 1ll*k1.x*k2.y-1ll*k1.y*k2.x;
}
int sign(long long k1){
	if (k1<0) return -1; else if (k1>0) return 1; else return 0;
}
vector<point> A;
struct CH{
	vector<point> A;
	vector<int> pre,ne;
	int posl,posr,lx,rx,ly,ry;
	int size(){return A.size();}
	point get(int &k){
		if (k<0) k+=A.size(); else if (k>=A.size()) k-=A.size();
		return A[k];
	}
	void clear(){
		A.clear(); pre.clear(); ne.clear();
	}
}B[MK];
int pd[N],ct=0,len,ta[N][MK][2],L[MK],R[MK],whe[N];
void ConvexHull(vector<point>&A, vector<point>&ans){ 
	if (A.size()==1){
		ans=A; A.clear(); return;
	}
	int flag=0;
	for (int i=2;i<A.size();i++) if (sign(cross(A[i]-A[i-1],A[i-1]-A[i-2]))!=0) flag=1;
	if (flag==0){
		ans=A; A.clear(); return;
	}
	int n=A.size(); ans.resize(n*2); int now=-1; ++ct;
	for (int i=0;i<A.size();i++){
        while (now>0&&sign(cross(ans[now]-ans[now-1],A[i]-ans[now-1]))<0) now--;
        ans[++now]=A[i];
    } int pre=now;
    for (int i=n-2;i>=0;i--){
        while (now>pre&&sign(cross(ans[now]-ans[now-1],A[i]-ans[now-1]))<0) now--;
        ans[++now]=A[i];
    } 
    //cout<<"fa "<<now<<endl;
    ans.resize(now); 
    for (int i=0;i<ans.size();i++) pd[ans[i].pos]=ct;
    n=0;
    for (int i=0;i<A.size();i++)
    	if (pd[A[i].pos]!=ct){
    		A[n]=A[i]; ++n;
    	}
    A.resize(n);
}
struct line{
	int where,l,step,empty;
	line(int _where,int _l,int _step):where(_where),l(_l),step(_step),empty(0){}
};
struct atom{
	point p;
	int where;
	int operator < (const atom k1)const{return cross(p,k1.p)>0;}
	int operator > (const atom k1)const{return cross(p,k1.p)<0;}
};
vector<line>C,D;
vector<point>Lp,Rp;
int takeC(line& L,point &res){
	if (L.empty) return 0;
	res=B[L.where].get(L.l); res.x-=o.x; res.y-=o.y;
	if (res.x<=0||pd[res.pos]==ct){L.empty=1; return 0;}
	pd[res.pos]=ct; L.l+=L.step; 
	return 1;
}
int takeD(line& L, point &res){
	if (L.empty) return 0;
	res=B[L.where].get(L.l); res.x-=o.x; res.y-=o.y;
	if (res.x>=0||pd[res.pos]==ct){L.empty=1; return 0;}
	pd[res.pos]=ct; L.l+=L.step; 
	return 1;
}
int imp[N];
void getans(){
	for (int i=1;i<=m;i++){
		B[i].lx=2e9; B[i].rx=-2e9; B[i].ly=2e9; B[i].ry=-2e9;
		for (int j=0;j<B[i].A.size();j++){
			B[i].lx=min(B[i].lx,B[i].A[j].x);
			B[i].ly=min(B[i].ly,B[i].A[j].y);
			B[i].ry=max(B[i].ry,B[i].A[j].y);
			if (B[i].lx==B[i].A[j].x) B[i].posl=j;
			int pre=((j==0)?B[i].A.size()-1:j-1);
			int ne=((j+1==B[i].size())?0:j+1);
			if (cross(B[i].A[j]-B[i].A[pre],B[i].A[j]-B[i].A[ne])!=0){
				imp[j]=1;
			} else imp[j]=0;
		}
		for (int j=B[i].A.size()-1;j>=0;j--){
			B[i].rx=max(B[i].rx,B[i].A[j].x);
			if (B[i].rx==B[i].A[j].x) B[i].posr=j;
		}
		imp[B[i].posl]=imp[B[i].posr]=1;
		B[i].ne.resize(B[i].size());
		B[i].pre.resize(B[i].size());
		for (int j=0;j<B[i].size();j++)
			if (imp[j]){
				int ne=j;
				while (1){
					ne+=1; if (ne==B[i].size()) ne=0;
					B[i].pre[ne]=j; if (imp[ne]) break;
				}
				int pre=j;
				while (1){
					pre-=1; if (pre<0) pre=B[i].size()-1;
					B[i].ne[pre]=j; if (imp[pre]) break;
				}
			}
		if (B[i].size()>1) assert(B[i].posl!=B[i].posr);
	}
	
	//debug
	/*for (int i=1;i<=m;i++){
		cout<<"convex hull id "<<i<<endl;
		for (int j=0;j<B[i].size();j++) B[i].get(j).print();
		for (int j=0;j<B[i].size();j++) cout<<B[i].pre[j]<<" "; cout<<endl;
		for (int j=0;j<B[i].size();j++) cout<<B[i].ne[j]<<" "; cout<<endl;
	}*/
	for (int s=1;s<=m;s++){
		for (int i=0;i<B[s].size();i++){
			point now=B[s].get(i);
			ta[now.pos][s][0]=ta[now.pos][s][1]=i;
		}
		for (int t=s+1;t<=m;t++){
			int l=B[t].posl,r=B[t].posl;
			for (int i=0;i<B[s].size();i++){
				point now=B[s].get(i);
				//cout<<t<<" "<<l<<" "<<r<<" "<<B[t].size()<<" "<<B[t].pre[l]<<" "<<B[t].ne[l]<<endl;
				while (1){
					int ne=B[t].ne[l];
					if (sign(cross(B[t].get(l)-now,B[t].get(ne)-now))<0){
						l=ne; continue;
					}
					int pre=B[t].pre[l];
					if (sign(cross(B[t].get(l)-now,B[t].get(pre)-now))<0){
						l=pre; continue;
					}
					break;
				}
				while (1){
					int ne=B[t].ne[r];
					if (sign(cross(B[t].get(r)-now,B[t].get(ne)-now))>0){
						r=ne; continue;
					}
					int pre=B[t].pre[r];
					if (sign(cross(B[t].get(r)-now,B[t].get(pre)-now))>0){
						r=pre; continue;
					}
					break;
				}
				ta[now.pos][t][0]=l; ta[now.pos][t][1]=r;
			}
		}
	}
	//debug
	/*for (int i=1;i<=n;i++){
		cout<<"curp "<<i<<endl;
		for (int j=1;j<=m;j++){
			cout<<"curtoj"<<endl;
			point k=B[j].get(ta[i][j][0]); cout<<k.x<<" "<<k.y<<endl;
			k=B[j].get(ta[i][j][1]); cout<<k.x<<" "<<k.y<<endl;
			//cout<<ta[i][j][0]<<" "<<ta[i][j][1]<<endl;
		}
	}*/
	for (int s=1;s<=m;s++){
		for (int step=-1;step<=1;step+=2){
			for (int i=1;i<=m;i++) L[i]=B[i].posl,R[i]=B[i].posl;
			for (int id=B[s].posl;;id=(id+step+B[s].size())%B[s].size()){
				point now=B[s].get(id); C.clear(); D.clear();
				for (int t=s+1;t<=m;t++){
					if (now.x<B[t].lx){
						int pos=ta[now.pos][t][1];
						C.pb(line(t,(pos+1)%B[t].size(),1));
						C.pb(line(t,pos,-1));
					} else if (now.x>B[t].rx){
						int pos=ta[now.pos][t][0];
						D.pb(line(t,(pos+1)%B[t].size(),1));
						D.pb(line(t,pos,-1));
					} else {
						if (step==1){
							while (B[t].get(L[t]).x<now.x) L[t]--;
							while (B[t].get(R[t]).x<now.x) R[t]++;
							C.pb(line(t,L[t],-1));
							C.pb(line(t,R[t],1));
							int preL=(L[t]+1)%B[t].size(),preR=(R[t]+B[t].size()-1)%B[t].size();
							D.pb(line(t,preL,1));
							D.pb(line(t,preR,-1));
						} else {
							int pos=ta[now.pos][t][1];
							C.pb(line(t,pos,-1));
							C.pb(line(t,(pos+1)%B[t].size(),1));
							pos=ta[now.pos][t][0];
							D.pb(line(t,pos,-1));
							D.pb(line(t,(pos+1)%B[t].size(),1));
						}
					}
				}
				for (int t=1;t<=s;t++){
					while (B[t].get(L[t]).x<now.x) L[t]--;
					if (t==s){
						if (L[t]==id){
							D.pb(line(s,(id+1)%B[s].size(),1));
							C.pb(line(s,(id+B[s].size()-1)%B[s].size(),-1));
						} else {
							C.pb(line(s,L[t],-1));
							D.pb(line(s,(L[t]+B[t].size()-1)%B[t].size(), 1));
						}
					}
					C.pb(line(t,L[t],-1));
					int preL=(L[t]+1)%B[t].size(),preR=(R[t]+B[t].size()-1)%B[t].size();
					D.pb(line(t,preL,1));
				}

				vector<point> Cp,Dp;
				priority_queue<atom> QC;
				priority_queue<atom,vector<atom>,greater<atom> >QD;
				point cur; ct++; o=now;
				//cout<<"fa "<<C.size()<<endl;
				for (int i=0;i<C.size();i++){
					//cout<<"use "<<C[i].where<<" "<<C[i].l<<" "<<C[i].r<<endl;
					if (takeC(C[i],cur)){
						//debug
						//cout<<"putin "<<cur.x<<" "<<cur.y<<endl;
						QC.push((atom){cur,i});
					}
				}
				for (int i=1;i<=K&&!QC.empty();i++){
					atom k=QC.top(); QC.pop();
					Cp.pb(k.p);
					if (takeC(C[k.where],cur)) QC.push((atom){cur,k.where});
				}
				for (int i=0;i<D.size();i++){
					if (takeD(D[i],cur)) QD.push((atom){cur,i}); 
				}
				for (int i=1;i<=K&&!QD.empty();i++){
					atom k=QD.top(); QD.pop();
					Dp.pb(k.p);
					if (takeD(D[k.where],cur)) QD.push((atom){cur,k.where});
				}
				/*cout<<"point "<<now.x<<" "<<now.y<<" "<<now.pos<<endl;
				cout<<"Cp"<<endl;
				for (int i=0;i<Cp.size();i++) cout<<Cp[i].x<<" "<<Cp[i].y<<endl;
				cout<<"Dp"<<endl;
				for (int i=0;i<Dp.size();i++) cout<<Dp[i].x<<" "<<Dp[i].y<<endl;*/
				int pos=Dp.size()-1; int pr=0;
				for (int i=0;i<Cp.size();i++){
					if (i+1==Cp.size()||cross(Cp[i],Cp[i+1])!=0){
						while (pos>=0&&cross(Cp[i],Dp[pos])<0) pos--;
						if (i+3+pos<=K){
							for (int j=pr;j<=i;j++) put(o.pos,Cp[j].pos);
						}
						pr=i+1;
					}
				}
				pos=Cp.size()-1; pr=0;
				for (int i=0;i<Dp.size();i++){
					if (i+1==Dp.size()||cross(Dp[i],Dp[i+1])!=0){
						while (pos>=0&&cross(Dp[i],Cp[pos])>0) pos--;
						if (i+3+pos<=K) {
							for (int j=pr;j<=i;j++) put(o.pos,Dp[j].pos);
						}
						pr=i+1;
					}
				}
				if (id==B[s].posr) break;
			}
		}
	}
}
void solve(){
	scanf("%d%d",&n,&K); hashsign++; hashlen=0;
	for (int i=1;i<=n;i++) ans[i]=0; A.clear();
	for (int i=1;i<=n;i++){
		p[i].scan(); p[i].pos=i; A.push_back(p[i]);
	}
	sort(A.begin(),A.end());
	m=0;
	while (A.size()&&m<K){
		m++; ConvexHull(A,B[m].A);
	}
	getans();
	for (int i=1;i<=m;i++){
		for (int j=0;j<B[i].A.size();j++) B[i].A[j].y=-B[i].A[j].y;
		reverse(B[i].A.begin(),B[i].A.end());
	}
	getans();
	for (int i=1;i<=n;i++){
		printf("%d",ans[i]); if (i==n) puts(""); else putchar(' ');
	}
	for (int i=1;i<=m;i++) B[i].clear();
}
int main(){
	int t; scanf("%d",&t);
	for (;t;t--) solve();
	return 0;
}
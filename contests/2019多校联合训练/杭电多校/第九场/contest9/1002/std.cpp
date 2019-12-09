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
const int N=110000;
struct atom{
	int x,y;
};
vector<atom> A[4],x,y;
char ch[10];
int n,m,K;
void readpoint(){
	int x,y; scanf("%d%d%s",&x,&y,ch+1);
	int z=0;
	if (ch[1]=='L') z=0; else if (ch[1]=='R') z=1; else if (ch[1]=='D') z=2; else z=3;
	A[z].push_back((atom){x,y});
}
struct atom2{
	int x,y,pd;
};
vector<atom2>Q;
int B[N],len,C[N];
void add(int k1){
	for (;k1<=len;k1+=k1&(-k1)) C[k1]++;
}
int find(int k1){
	int ans=0;
	for (;k1;k1-=k1&(-k1)) ans+=C[k1];
	return ans;
}
int comparex(atom2 k1,atom2 k2){
	return k1.x<k2.x;
}
int comparey(atom2 k1,atom2 k2){
	return k1.y<k2.y;
}
long long getcross(){
	Q.clear();
	for (int i=0;i<x.size();i++) Q.push_back((atom2){x[i].x,x[i].y,0});
	for (int i=0;i<y.size();i++) Q.push_back((atom2){y[i].x,y[i].y,1});
	sort(Q.begin(),Q.end(),comparey); len=0;
	for (int i=0;i<Q.size();i++) Q[i].y=++len;
	sort(Q.begin(),Q.end(),comparex);
	//cout<<"getcross"<<endl;
	//for (int i=0;i<Q.size();i++) cout<<Q[i].x<<" "<<Q[i].y<<" "<<Q[i].pd<<endl;
	for (int i=1;i<=len;i++) C[i]=0;
	long long ans=0;
	int tot=0;
	for (int i=0;i<Q.size();i++)
		if (Q[i].pd==0) ans+=tot-find(Q[i].y); else {add(Q[i].y); ++tot;}
	return ans;
}
void solve(){
	scanf("%d%d%d",&n,&m,&K);
	for (int i=0;i<4;i++) A[i].clear();
	for (int i=1;i<=K;i++) readpoint();
	long long cross=0;
	x=A[0],y=A[2]; cross+=getcross();
	x=A[0],y=A[3];
	for (int i=0;i<x.size();i++) x[i].y=m-x[i].y;
	for (int i=0;i<y.size();i++) y[i].y=m-y[i].y;
	cross+=getcross();
	x=A[1]; y=A[2];
	for (int i=0;i<x.size();i++) x[i].x=n-x[i].x;
	for (int i=0;i<y.size();i++) y[i].x=n-y[i].x;
	cross+=getcross();
	x=A[1]; y=A[3];
	for (int i=0;i<x.size();i++) x[i].x=n-x[i].x,x[i].y=m-x[i].y;
	for (int i=0;i<y.size();i++) y[i].x=n-y[i].x,y[i].y=m-y[i].y;
	cross+=getcross();
	long long totV=cross+K*2+4;
	long long totE=4+K*2+cross*2;
	printf("%lld\n",totE-totV+1);
}
int main(){
	int t; scanf("%d",&t);
	for (;t;t--) solve();
	return 0;
}
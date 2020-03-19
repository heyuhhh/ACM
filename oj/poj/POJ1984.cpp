#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
using namespace std;

typedef pair<int,int> pii;
const int N = 40005, K = 10005;
int n,m,k;
int f[N];
struct query{
	int p1,p2,t,id;
	bool operator < (const query &A)const{
		return A.t<t;
	}
}q[K];
struct farm{
	int X,Y;
}p[N];
struct link{
	int x,y,dis;
	char c;
}l[N];
int find(int x){
	if(x==f[x]) return x;
	int tmp=f[x];
	f[x]=find(f[x]);
	p[x].X+=p[tmp].X;
	p[x].Y+=p[tmp].Y;
	return f[x];
}
void Union(int x,int y,int dir,int d){
	int fx=find(x),fy=find(y);
	f[fx]=fy;
	if(dir==1) p[fx].X=p[y].X-d-p[x].X,p[fx].Y=p[y].Y-p[x].Y;//x在y的西面 
	else if(dir==2) p[fx].X=p[y].X+d-p[x].X,p[fx].Y=p[y].Y-p[x].Y ;
	else if(dir==3) p[fx].Y=p[y].Y-d-p[x].Y,p[fx].X=p[y].X-p[x].X;//x在y的南面 
	else p[fx].Y=d-p[x].Y+p[y].Y,p[fx].X=p[y].X-p[x].X;
}
int main(){
	scanf("%d%d",&n,&m); 
	for(int i=1;i<=m;i++){scanf("%d%d%d %c",&l[i].x,&l[i].y,&l[i].dis,&l[i].c);}
	scanf("%d",&k);
	priority_queue <query> que;
	for(int i=1,x,y,t;i<=k;i++){
		scanf("%d%d%d",&q[i].p1,&q[i].p2,&q[i].t);q[i].id=i;
		que.push(q[i]);
	}
	priority_queue <pii ,vector<pii>,greater<pii> > ans ; 
	for(int i=1;i<=N-5;i++) f[i]=i;
	for(int i=1,x,y,dis,pd;i<=m;i++){
		char c;
		x=l[i].x;y=l[i].y;dis=l[i].dis;c=l[i].c;
		if(c=='E') pd=1;else if(c=='W') pd=2;else if(c=='N') pd=3;else pd=4;
		int fx=find(x),fy=find(y);
		if(fx!=fy) Union(x,y,pd,dis);
		while(que.top().t==i && !que.empty()){
			query now=que.top();que.pop();
			int now1=now.p1,now2=now.p2;
			if(find(now1)==find(now2)){
				int xx = abs(p[now1].X-p[now2].X),yy=abs(p[now1].Y-p[now2].Y);
				ans.push(make_pair(now.id,xx+yy));
			}else ans.push(make_pair(now.id,-1)); 
		}
	}
	while(!ans.empty()){
		printf("%d\n",ans.top().second);
		ans.pop();
	}
	return 0;
}

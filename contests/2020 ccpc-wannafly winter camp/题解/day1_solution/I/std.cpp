#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
struct tree{
	int l,r,size;
}t[30000000];
queue<int>Q;
int root[410000],n,m,ma[410000],se[410000],T[410000],A[410000],len,s[10000000],head;
int getnew(){
	if (head) return s[head--]; else return ++len;
}
void del(int k1){
	s[++head]=k1; t[k1]=(tree){0,0};
}
int totmerge2=0,totpush=0,totinsert=0;
int merge(int k1,int k2){
	if (k1==0&&k2==0) return k1;
	int now=getnew(); t[now].size=t[k1].size+t[k2].size;
	t[now].l=merge(t[k1].l,t[k2].l);
	t[now].r=merge(t[k1].r,t[k2].r); totmerge2++;
	return now;
}
int merge2(int k1,int k2){
	if (k1==0||k2==0) return k1+k2;
	t[k1].size=t[k1].size+t[k2].size;
	t[k1].l=merge2(t[k1].l,t[k2].l);
	t[k1].r=merge2(t[k1].r,t[k2].r);
	del(k2); totmerge2++;
	return k1;
}
int merge3(int k1,int k2){
	if (k2==0) return k1;
	if (k1==0) k1=getnew();
	t[k1].size=t[k1].size+t[k2].size;
	t[k1].l=merge3(t[k1].l,t[k2].l);
	t[k1].r=merge3(t[k1].r,t[k2].r);
	totmerge2++;
	if (t[k1].size==0){
		del(k1); return 0;
	} else return k1;
}
int insert(int k1,int k2,int k3,int k4,int k5){
	if (k1==0) k1=getnew();
	t[k1].size+=k5;
	if (k2==k3) return k1;
	int mid=k2+k3>>1;
	if (mid>=k4)
		t[k1].l=insert(t[k1].l,k2,mid,k4,k5);
	else t[k1].r=insert(t[k1].r,mid+1,k3,k4,k5);
	totinsert++;
	return k1;
}
int insert(int k1,int k2,int k3=1){
	k1=insert(k1,1,n,k2,k3);
	return k1;
}
void change(int k1){
	int l=k1*2,r=k1*2+1;
	if (ma[l]>ma[r]){
		ma[k1]=ma[l]; se[k1]=max(ma[r],se[l]); T[k1]=T[l];
	} else if (ma[l]<ma[r]){
		ma[k1]=ma[r]; se[k1]=max(ma[l],se[r]); T[k1]=T[r];
	} else {
		ma[k1]=ma[l]; se[k1]=max(se[l],se[r]); T[k1]=T[l]+T[r];
	}
}
void print(int k1,int k2,int k3){
	if (k1==0) return;
	printf("%d %d %d\n",k2,k3,t[k1].size);
	int mid=k2+k3>>1;
	print(t[k1].l,k2,mid); print(t[k1].r,mid+1,k3);
}
void buildtree(int k1,int k2,int k3){
	A[k1]=1e9;
	if (k2==k3){
		scanf("%d",&ma[k1]); se[k1]=0; T[k1]=1;
		root[k1]=insert(root[k1],ma[k1]); 
		return;
	}
	int mid=k2+k3>>1;
	buildtree(k1*2,k2,mid);
	buildtree(k1*2+1,mid+1,k3);
	root[k1]=merge(root[k1*2],root[k1*2+1]);
	change(k1);
}
void change(int k1,int k2){
	if (k2>=ma[k1]) return;
	root[k1]=insert(root[k1],ma[k1],-T[k1]);
	root[k1]=insert(root[k1],k2,T[k1]);
	ma[k1]=k2; A[k1]=k2;
}
void pushdown(int k1){
	if (A[k1]>0){
		totpush++;
		change(k1*2,A[k1]); change(k1*2+1,A[k1]); A[k1]=1e9;
	}
}
void rel(int k1){
	if (k1==0) return; 
	rel(t[k1].l); rel(t[k1].r); del(k1); 
}
int totnum=0;
int change(int k1,int k2,int k3,int k4,int k5,int k6){
	if (k2>k5||k3<k4||ma[k1]<=k6) return 0;
	totnum++;
	if (k2>=k4&&k3<=k5&&se[k1]<k6){
		int num=insert(insert(0,ma[k1],-T[k1]),k6,T[k1]);
	//cout<<"del "<<k2<<" "<<k3<<" "<<num<<" "<<T[k1]<<" "<<ma[k1]<<" "<<k6<<endl;
	//	print(num,1,n);
		change(k1,k6); return num;
	}
	int mid=k2+k3>>1; pushdown(k1);
	int num=merge2(change(k1*2,k2,mid,k4,k5,k6),change(k1*2+1,mid+1,k3,k4,k5,k6));
	root[k1]=merge3(root[k1],num); change(k1);
	return num;
}
vector<int>B;
void gettree(int k1,int k2,int k3,int k4,int k5){
	if (k2>k5||k3<k4) return;
	if (k2>=k4&&k3<=k5){
		B.push_back(root[k1]); return;
	}
	int mid=k2+k3>>1; pushdown(k1);
	gettree(k1*2,k2,mid,k4,k5);
	gettree(k1*2+1,mid+1,k3,k4,k5);
}
int findans(int k1,int k2,int k3){
	if (k1==k2) return k1;
	int now=0,mid=k1+k2>>1;
	for (int i=0;i<B.size();i++) now+=t[t[B[i]].l].size;
	if (now>=k3){
		for (int i=0;i<B.size();i++) B[i]=t[B[i]].l;
		return findans(k1,mid,k3);
	} else {
		for (int i=0;i<B.size();i++) B[i]=t[B[i]].r;
		return findans(mid+1,k2,k3-now);
	}
}
int main(){
//	freopen("kth.in","r",stdin);
//	freopen("kth.out","w",stdout);
	scanf("%d%d",&n,&m);
	buildtree(1,1,n);
	for (;m;m--){
		int k1,k2,k3; scanf("%d%d%d",&k1,&k2,&k3);
		if (m%1000==0) cerr<<totmerge2<<" "<<totpush<<" "<<totinsert<<endl; 
		if (k1==1){
			int k4; scanf("%d",&k4);
			rel(change(1,1,n,k2,k3,k4));
		} else {
			int k4; scanf("%d",&k4); B.clear();
			gettree(1,1,n,k2,k3);
			printf("%d\n",findans(1,n,k4));
		}
	}
	return 0;
}

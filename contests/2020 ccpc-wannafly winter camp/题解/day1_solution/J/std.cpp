#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cassert>
#include <vector>
using namespace std;
struct atom{
	int w,c;
	void scan(){
		static char ch[10];
		scanf("%d%s",&c,ch+1);
		if (ch[1]=='A') w=13;
		else if (ch[1]=='K') w=12;
		else if (ch[1]=='Q') w=11;
		else if (ch[1]=='J') w=10;
		else if (ch[1]=='T') w=9;
		else w=ch[1]-'1';
	}
};
int operator < (atom k1,atom k2){
	return k1.w<k2.w||(k1.w==k2.w&&k1.c<k2.c);
}
struct score{
	int w,f;
	score(int _w,vector<int>& A){
		w=_w; f=0;
		for (int i=0;i<A.size();++i) f=f*20+A[i];
	}
	score(){}
};
// w=0 
int operator < (score k1, score k2){
	return k1.w<k2.w||(k1.w==k2.w&&k1.f<k2.f);
}
int oc[14][5],o[14];
bool checkSF(score& res){
	for (int c=0;c<4;++c){
		for (int i=9;i>=0;--i){
			int flag=0;
			for (int j=0;j<=4;++j)
				if (!oc[i+j][c]){
					flag=1; break;
				}
			if (flag) continue;
			vector<int> A;
			for (int j=4;j>=0;j--) A.push_back(i+j);
			res=score(0,A);
			return 1;
		}
	}
	return 0;
}
bool checkFour(score& res){
	for (int i=13;i;i--)
		if (o[i]==4){
			vector<int> A;
			for (int k=0;k<4;k++) A.push_back(i);
			for (int j=13;j;j--)
				if (i!=j&&o[j]){
					A.push_back(j);
					res=score(-1,A);
					return 1;
				}
		}
	return 0;
}
bool checkFH(score &res){
	for (int i=13;i;i--)
		if (o[i]==3){
			vector<int> A;
			for (int k=0;k<3;k++) A.push_back(i);
			for (int j=13;j;j--)
				if (i!=j&&o[j]>=2){
					for (int k=0;k<2;k++) A.push_back(j);
					res=score(-2,A);
					return 1;
				}
		}
	return 0;
}
bool checkS(score &res){
	for (int c=0;c<4;c++){
		vector<int> A;
		for (int i=13;i;i--)
			if (oc[i][c]){
				A.push_back(i);
				if (A.size()==5){
					res=score(-3,A);
					return 1;
				}
			}
	}
	return 0;
}
bool checkF(score &res){
	for (int i=9;i>=0;i--){
		int flag=0;
		for (int j=4;j>=0;j--)
			if (!o[i+j]){
				flag=1; break;
			}
		if (flag) continue; 
		vector<int> A;
		for (int j=4;j>=0;j--)
			A.push_back(i+j);
		res=score(-4,A);
		return 1;
	}
	return 0;
}
bool checkThree(score &res){
	for (int i=13;i;i--)
		if (o[i]>=3){
			vector<int> A;
			for (int k=0;k<3;k++) A.push_back(i);
			for (int j=13;j;j--)
				if (i!=j&&o[j]){
					A.push_back(j);
					if (A.size()==5){
						res=score(-5,A);
						return 1;
					}
				}
		}
	return 0;
}
bool checkTT(score &res){
	for (int i=13;i;i--)
		if (o[i]>=2){
			vector<int> A;
			for (int k=0;k<2;k++) A.push_back(i);
			for (int j=i-1;j;j--)
				if (o[j]>=2){
					for (int k=0;k<2;k++) A.push_back(j);
					for (int x=13;x;x--)
						if (o[x]&&x!=i&&x!=j){
							A.push_back(x);
							res=score(-6,A);
							return 1;
						}
				}
		}
	return 0;
}
bool checkT(score &res){
	for (int i=13;i;i--)
		if (o[i]>=2){
			vector<int> A;
			for (int k=0;k<2;k++) A.push_back(i);
			for (int j=13;j;j--)
				if (o[j]&&j!=i){
					A.push_back(j);
					if (A.size()==5){
						res=score(-7,A);
						return 1;
					}
				}
		}
	return 0;
}
void getL(score &res){
	vector<int> A;
	for (int i=13;i;i--)
		if (o[i]){
			A.push_back(i);
			if (A.size()==5){
				res=score(-8,A);
				return;
			}
		}
	res.w=-8;
}
score get(vector<atom>& A){
	memset(oc,0x00,sizeof oc);
	memset(o,0x00,sizeof o);
	for (int i=0;i<A.size();++i) oc[A[i].w][A[i].c]++,o[A[i].w]++;
	o[0]=o[13]; for (int i=0;i<=4;i++) oc[0][i]=oc[13][i];
	score res;
	if (checkSF(res)) return res;
	if (checkFour(res)) return res;
	if (checkFH(res)) return res;
	if (checkS(res)) return res;
	if (checkF(res)) return res;
	if (checkThree(res)) return res;
	if (checkTT(res)) return res;
	if (checkT(res)) return res;
	getL(res); return res;
}
vector<atom> x,y;
int used[14][4],num[14],C[10][10];
int ans[3],cou=0;
int cmp(vector<atom>& B){
	B.push_back(x[0]); B.push_back(x[1]);
	score k1=get(B);
	B.pop_back(); B.pop_back();
	B.push_back(y[0]); B.push_back(y[1]);
	score k2=get(B);
	int res=0;
	if (k1<k2) res=2; else if (k2<k1) res=0; else res=1;
	/*if (res==2&&rand()%1000==0){
		cout<<"diff "<<res<<endl;
		cout<<"First: "<<k1.w<<" "<<k1.f<<endl;
		cout<<"Second: "<<k2.w<<" "<<k2.f<<endl;
		for (int i=1;i<=13;i++) cout<<o[i]<<" "; cout<<endl;
		for (int i=0;i<B.size();i++) cout<<B[i].c<<" "<<B[i].w<<endl;
		int k; cin>>k;
	}*/
	return res;
}
void pick(int pos,vector<int>& chosen, vector<pair<int,int> >& A){
	if (pos==A.size()){
		for (int c=0;c<4;c++){
			int flag=0;
			int way=1;
			for (int i=0;i<A.size();i++)
				if (used[A[i].first][c]){
					way*=C[num[A[i].first]][A[i].second];
				} else 
					way*=C[num[A[i].first]-1][A[i].second];
			for (int i=0;i<chosen.size();++i)
				if (used[chosen[i]][c]){
					flag=1; continue;
				}
			if (flag) continue;
			vector<atom> B;
			for (int i=0;i<chosen.size();++i) B.push_back((atom){chosen[i],c});
			for (int i=0;i<A.size();i++)
				for (int j=0;j<A[i].second;++j)
					B.push_back((atom){A[i].first,4});
			int res=cmp(B);
			ans[res]+=way;
			cou+=way;
		}
		return;
	}
	if (chosen.size()+A.size()-pos>3) pick(pos+1,chosen,A);
	chosen.push_back(A[pos].first); A[pos].second-=1;
	pick(pos+1,chosen,A);
	chosen.pop_back();
	A[pos].second+=1;
}
void getans(vector<pair<int,int> > A){
	int tot=1;
	for (int i=0;i<A.size();++i) tot*=C[num[A[i].first]][A[i].second];
	cou=0;
	if (A.size()>=3){
		vector<int>B;
		pick(0,B,A);
	}
	int rem=tot-cou;
	//cout<<rem<<endl;
	vector<atom> B;
	for (int i=0;i<A.size();i++)
		for (int j=1;j<=A[i].second;++j)
			B.push_back((atom){A[i].first,4});
	int res=cmp(B);
	ans[res]+=rem;
}
void calc(int pos,int size,vector<pair<int,int> > A){
	if (pos==14){
		if (size!=5) return;
		getans(A); return;
	}
	calc(pos+1,size,A);
	for (int i=1;i<=num[pos]&&size+i<=5;++i){
		A.push_back(make_pair(pos,i));
		calc(pos+1,size+i,A);
		A.pop_back();
	}
}
int gcd(int k1,int k2){
	if (k2==0) return k1; return gcd(k2,k1%k2);
}
void print(int k1,int k2){
	int d=gcd(k1,k2);
	printf("%d/%d\n",k1/d,k2/d);
	//printf("%.11lf\n",1.0*k1/k2);
}
void solve(){
	x.clear(); y.clear();
	memset(ans,0x00,sizeof ans);
	memset(used,0x00,sizeof used);
	for (int i=1;i<=13;i++) num[i]=4;
	for (int i=0;i<2;i++){
		atom k1; k1.scan(); x.push_back(k1);
		used[k1.w][k1.c]=1; num[k1.w]--;
	}
	for (int i=0;i<2;i++){
		atom k1; k1.scan(); y.push_back(k1);
		used[k1.w][k1.c]=1; num[k1.w]--;
	}
	vector<pair<int,int> > A;
	calc(1,0,A);
	int all=ans[0]+ans[1]+ans[2];
	int call=1;
	for (int i=1;i<=5;i++) call=call*(48-i+1)/i;
	assert(all==call);
	print(ans[0],all);
	print(ans[1],all);
	print(ans[2],all);
}
int main(){
	for (int i=0;i<=9;i++){
		C[i][0]=1;
		for (int j=1;j<=i;j++) C[i][j]=C[i-1][j]+C[i-1][j-1];
	}
	int t; scanf("%d",&t);
	for (;t;t--) solve();
	return 0;
}
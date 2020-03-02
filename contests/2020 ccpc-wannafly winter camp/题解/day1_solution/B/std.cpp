#include <iostream>
#include <cmath>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cassert>
using namespace std;
char C(int k){
	if (k>=0&&k<26) return 'a'+k;
	if (k>=26&&k<52) return 'A'+(k-26);
	assert(0);
}
int N(char k){
	if (k>='a'&&k<='z') return int(k-'a');
	if (k>='A'&&k<='Z') return int(k-'A')+26;
	assert(0);
}
string decode(string res,string key){
	string K=key;
	while (K.length()<res.length()) K+=key;
	for (int i=0;i<res.length();++i)
		res[i]=C((N(res[i])-N(K[i])+52)%52);
	return res;
}
string A[1100];
int x[1100],y[1100];
int n,m;
char ch[1100];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) scanf("%d%d",&x[i],&y[i]);
	for (int i=1;i<=n;i++){
		scanf("%s",ch+1); A[i]=string(ch+1);
	}
	for (int i=m;i;i--) A[y[i]]=decode(A[y[i]],A[x[i]]);
	for (int i=1;i<=n;i++) printf("%s\n",A[i].c_str());
	return 0;
}
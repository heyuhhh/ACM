#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;
int q;
int main(){
	cin>>q;
	for(int i=1;i<=q;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		int len = r-l+1;
		if(len%2){
			if(l%2) printf("%d\n",len/2+r);
			else printf("%d\n",r-len/2);
		}else{
			if(l%2) printf("%d\n",len/2);
			else printf("%d\n",-len/2);
		}
	}
}

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
#define mp make_pair
#define pb push_back
int n;
char ch[11000];
void solve(){
	scanf("%s",ch+1); n=strlen(ch+1);
	int now=1;
	while (now<=n&&ch[now]=='y') now++;
	if (now>n||ch[now]!='z'){
		printf("%s\n",ch+1);
	} else {
		ch[now]='b';
		printf("%s\n",ch+1);
	}
}
int main(){
	int t; scanf("%d",&t);
	for (;t;t--) solve();
	return 0;
}
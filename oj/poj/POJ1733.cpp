#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

typedef long long ll;
const int N = 15005;
int f[N],v[N];
map<ll,int> mp;
ll n,x,y;
int q,tot;

int find(int x){
	if(x==f[x]) return x;
	int tmp = f[x];
	f[x]=find(f[x]);
	v[x]+=v[tmp];
	if(v[x]>=2) v[x]-=2;
	return f[x];
}

int main(){
	cin>>n>>q;
	int flag = 0,ans = q;
	for(int i=0;i<=10001;i++) f[i]=i,v[i]=0;
	for(int i=1;i<=q;i++){
		char s[10];
		scanf("%lld%lld %s",&x,&y,s);
		if(flag) continue ;
		if(!mp[x]) mp[x]=++tot;
		if(!mp[y+1])mp[y+1]=++tot;
		int fx=find(mp[x]),fy=find(mp[y+1]),pd;
		if(s[0]=='e') pd=1;else pd=0;
		if(fx==fy){
			int now = (v[mp[x]]+v[mp[y+1]])%2;
			if((pd && !now) || (!pd &&now)) continue;
			else{
				ans=i-1;
				flag=1;
				continue;
			} 
		}
		f[fx]=fy;
		if(pd) v[fx]=(v[mp[x]]+v[mp[y+1]])%2;
		else if(!pd) v[fx]=(v[mp[x]]+v[mp[y+1]]+1)%2;
	}
	printf("%d",ans);
	return 0;
}

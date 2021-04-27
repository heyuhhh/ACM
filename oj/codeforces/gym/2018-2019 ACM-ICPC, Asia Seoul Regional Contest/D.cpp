#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=37;
char s[MAXN];
int main() {
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	#endif
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for(int i=0; i<n; i++) {
		cin >> s;
		int l=strlen(s);
		bool ok=false;
		switch(s[l-1]) {
			case 'a': ok=true; s[l]='s'; s[l+1]=0; break;
			case 'i': case 'y': 
					  ok=true; s[l-1]='i'; s[l]='o'; s[l+1]='s'; s[l+2]=0; break;
			case 'l': ok=true; s[l]='e'; s[l+1]='s'; s[l+2]=0; break;
			case 'n': ok=true; strcpy(s+l-1, "anes"); break;
			case 'e': if(l-2>=0 && s[l-2]=='n') {ok=true; strcpy(s+l-2,"anes"); } break;
			case 'o': ok=true; strcpy(s+l-1, "os"); break;
			case 'r': ok=true; strcpy(s+l-1, "res"); break;
			case 't': ok=true; strcpy(s+l-1, "tas"); break;
			case 'u': ok=true; strcpy(s+l-1, "us"); break;
			case 'v': ok=true; strcpy(s+l-1, "ves"); break;
			case 'w': ok=true; strcpy(s+l-1, "was"); break;
		}
		if(!ok) strcpy(s+l, "us");
		cout << s << '\n';
	}
}

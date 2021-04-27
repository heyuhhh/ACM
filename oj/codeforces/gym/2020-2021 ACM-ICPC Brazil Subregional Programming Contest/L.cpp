#include <bits/stdc++.h>
using namespace std;


const int MAXM = 47;
char mtx[MAXM][MAXM];
unsigned idx[MAXM][MAXM];
struct node {
	int size;
	char cnt[26];
	node(){memset(cnt,0,sizeof cnt); size=0;}
	bool operator<(const node&r) const {
		return memcmp(cnt,r.cnt,26)<0;
	}
	bool operator==(const node&r) const {
		return memcmp(cnt,r.cnt,26)==0;
	}
	void operator-=(const node&r) {
		for(int i=0; i<26; i++) cnt[i]-=r.cnt[i];
	}
};
set<node> st;
node hen[MAXM][MAXM], 
	shu[MAXM][MAXM], 
	zuo[MAXM][MAXM],
	you[MAXM][MAXM];

void run() {
	int l,c; cin >> l >> c;
	for(int i=1; i<=l; i++) {
		cin >> &mtx[i][1];
	}
	memset(idx,0,sizeof idx);
	int n; cin >> n;
	for(int i=0; i<n; i++) {
		string x; cin >> x;
		node k;
		for(int i=0; i<(int)x.length(); i++) {
			k.cnt[x[i]-'A']++;
		}
		k.size=x.length();
		st.insert(k);
	}
	for(int i=1; i<=l; i++) {
		for(int j=1; j<=c; j++) {
			shu[i][j]=shu[i-1][j];
			shu[i][j].cnt[mtx[i][j]-'A']++;
			
			hen[i][j]=hen[i][j-1];
			hen[i][j].cnt[mtx[i][j]-'A']++;
			
			you[i][j]=you[i-1][j-1];
			you[i][j].cnt[mtx[i][j]-'A']++;
		}
	}
	for(int i=1; i<=l; i++) {
		for(int j=c; j>=1; j--) {
			zuo[i][j]=zuo[i-1][j+1];
			zuo[i][j].cnt[mtx[i][j]-'A']++;
		}
	}
	{
	int z=0;
	for(auto it=st.begin(); it!=st.end(); it++, z++) {
		for(int i=1; i<=l; i++) {
			for(int j=it->size; j<=c; j++) {
				node k=hen[i][j];
				k-=hen[i][j-it->size];
				if(k==*it) {
					for(int jj=j-it->size+1; jj<=j; jj++) {
						idx[i][jj]|=1<<z;
					}
				}
			}
		}
		for(int i=it->size; i<=l; i++) {
			for(int j=1; j<=c; j++) {
				node k=shu[i][j];
				k-=shu[i-it->size][j];
				if(k==*it) {
					for(int ii=i-it->size+1; ii<=i; ii++) {
						idx[ii][j]|=1<<z;
					}
				}
			}
		}
		for(int i=it->size; i<=l; i++) {
			for(int j=it->size; j<=c; j++) {
				node k=you[i][j];
				k-=you[i-it->size][j-it->size];
				if(k==*it) {
					for(int t=0; t<it->size; t++) {
						idx[i-t][j-t]|=1<<z;
					}
				}
			}
		}
		for(int i=it->size; i<=l; i++) {
			for(int j=c-it->size+1; j>=1; j--) {
				node k=zuo[i][j];
				k-=zuo[i-it->size][j+it->size];
				if(k==*it) {
					for(int t=0; t<it->size; t++) {
						idx[i-t][j+t]|=1<<z;
					}
				}
			}
		}
	}
	}
	int ans=0;
	for(int i=1; i<=l; i++) {
		for(int j=c; j>=1; j--) {
			if(__builtin_popcount(idx[i][j])>1) {
				ans++;
			}
		}
	}
	cout << ans << '\n';
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(20);
	//int T; cin >> T; while (T--)
	run();
	return 0;
}


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5005, M = 65, MOD = 1e9 + 7;
 
char s[N], t[N];
int n, m;
int dp[N][M][M][2];
int pow10[N];
 
void init() {
	for (register int i = 1; i <= n; i++) {
		for (register int j = 0; j < m; j++) {
			for (register int k = 0; k < m; k++) {
				for (register int p = 0; p < 2; p++) {
                    dp[i][j][k][p] = -1;
				}
			}
		}
	}
}
 
inline void add(int& x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
}
 
int solve(int cur, int k1, int k2, int lim) {
    if (cur == n + 1) {
		return (k1 == 0);
	}
	if (dp[cur][k1][k2][lim] != -1) {
		return dp[cur][k1][k2][lim];
	}
 
	int up = (lim ? s[cur] - '0' : 9);
	int res = 0;
	for (int i = 0; i <= up; i++) {
		add(res, solve(cur + 1, ((k1 + i * k2 - i * pow10[n - cur]) % m + m) % m, (k2 + i) % m, (lim) && (i == up)));
	}
	return dp[cur][k1][k2][lim] = res;
}
inline void sub1(char *t) {
	int l=strlen(t);
	t[l-1]--;
	for(int i=l-1; i>=0 && t[i]<'0'; i--) {
		t[i]+=10, t[i-1]--;
	}
	int now=0;
	for(;t[now]=='0';now++);
	if(now!=0) {
		for(int i=now,j=0; i<=l; i++,j++) {
			t[j]=t[i];
		}
	}
}
 
void run() {
    scanf("%s%s%d", s + 1, t + 1, &m);
	sub1(s+1);
    n = strlen(s + 1);
    
    pow10[0] = 1;
    for (int i = 1; i <= n; i++) {
        pow10[i] = pow10[i - 1] * 10 % m;
    }
	init();
    
	int ans = MOD - solve(1, 0, 0, 1);
 
	strcpy(s + 1, t + 1);
 
	n = strlen(s + 1);
 
    pow10[0] = 1;
    for (int i = 1; i <= n; i++) {
        pow10[i] = pow10[i - 1] * 10 % m;
    }
	init();
 
	add(ans, solve(1, 0, 0, 1));
    printf("%d\n", ans);
}
 
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
	int T; scanf("%d", &T);
	while (T--) run();
}
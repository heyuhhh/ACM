#include <bits/stdc++.h>

using namespace std;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const double PI = 2.0 * acos(0.0);


typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORS(i,a,b,s) for (int i = (a); i < (b); i=i+(s))
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)

int cab[70];

int dp[70][1000]; // max number of pieces to get to _2.

int main(){
	int n,g; cin >> n >> g;

	FOR(i,0,n) cin >> cab[i];
	FOR(i,0,n) cab[i] -= 5;

	FOR(i,0,n+1) FOR(l,0,g+1) dp[i][l] = -1;

	dp[0][0] = 0;
	FOR(i,1,n+1) FOR(l,0,g+1) {
		dp[i][l] = dp[i-1][l];

		if (l - cab[i-1] < 0) continue;
		if (dp[i-1][l - cab[i-1]] == -1) continue;

		dp[i][l] = max(dp[i][l], dp[i-1][l-cab[i-1]] + 1);
	}

	double maxScore = -1;
	FOR(l,0,g+1) if (dp[n][l] != -1) {
		double avail = (dp[n][l] + 2) * 5 - (g - l);
		if (avail < 0) continue;
		double score = avail / (dp[n][l]+1);
		if (score > 5) continue;
		maxScore = max(maxScore,score);
	}

	if (maxScore < 0) cout << "impossible" << endl; else cout << fixed << setprecision(10) << maxScore << endl;
}

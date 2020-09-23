#include <iostream>
#include <vector>
#include <utility>
using namespace std;
const int MAX_N = 61;
const int MAX_D = 1001;
vector<vector<pair<int,int>>> dp(MAX_N, vector<pair<int,int>>(MAX_D, make_pair(-1,1)));

int main()
{
	int n,d; cin >> n >> d;
	for (int i = 0; i <= 5; ++i)
		dp[0][i+5] = make_pair(5-i, 1);
	for (int i = 1; i <= n; ++i)
	{
		int x; cin >> x; x -= 10;
		for (int j = 0; j <= d; ++j)
		{
			dp[i][j] = dp[i-1][j];
			for (int k = 0; k <= 10; ++k)
			{
				if (j - x - k < 0 || dp[i-1][j-x-k].first == -1) 
					continue;
				int extra = dp[i-1][j-x-k].first + 10 - k;
				int conn = dp[i-1][j-x-k].second + 1;
				if (extra > conn * 5) 
					continue;
				double v = 1.0 * extra / conn;
				double w = 1.0 * dp[i][j].first / dp[i][j].second;
				if (v > w)
					dp[i][j] = make_pair(extra,conn);
			}
		}
	}
	if (dp[n][d].first == -1)
		printf("impossible\n");
	else
		printf("%.8f\n",1.0 * dp[n][d].first / dp[n][d].second);
}

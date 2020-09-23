#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <sstream>
#include <stack>
#include <queue>
#include <map>
#include <climits>
#include <cstdio>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <functional>
#include <bitset>
#include <cctype>
#include <cassert>
#include <cstdint>
using namespace std;
#ifdef DEBUG
#define db(a) (cout << (#a) << " = " << (a) << endl)
#else
#define db(a)
#endif
using ll = int64_t;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

	vector<int> fib {1, 2};
	while(fib[fib.size()-1] < 1000001) fib.push_back(fib[fib.size()-1] + fib[fib.size()-2]);
	
	int N;
	cin>>N;
	vector<pair<int,int>> v;
	int first1 = -1;
	for(int n=0;n<N;n++)
	{
		int x;
		cin>>x;
		if(x == 1 && first1 == -1) first1 = n;
		else if(x == 1)
		{
			cout << first1+1 << " " << n+1 << "\n";
			return 0;
		}
		v.push_back({x, n});
	}
	sort(v.begin(), v.end());
	bool found = false;
	for(size_t i=0;i<v.size()-1;i++)
	{
		auto it = lower_bound(fib.begin(), fib.end(), v[i].first);
		if(it == fib.end() || it+1 == fib.end() || *it != v[i].first) continue;
		int f2 = *(it+1);
		auto itv = lower_bound(v.begin(), v.end(), pair<int,int>(f2, 0));
		if(itv == v.end() || itv->first != f2) continue;
		cout << v[i].second+1 << " " << itv->second+1 << "\n";
		found = true;
	}
	if(!found) cout << "impossible\n";

  return 0;
}

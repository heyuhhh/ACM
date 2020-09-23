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
#include <limits>
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
  
  int N;
  cin>>N;
  int minv = 0;
  int maxv = numeric_limits<int>::max();
  bool even = true;
  int last = 0;
  for(int n=0;n<N;n++)
  {
		int x;
		cin>>x;
		if(even) maxv = min(maxv, (last += x));
		else minv = max(minv, (last += -x));
		even = !even;
	}
	if(minv > maxv) cout << "0\n";
	else cout << maxv - minv + 1 << "\n";
  
  return 0;
}

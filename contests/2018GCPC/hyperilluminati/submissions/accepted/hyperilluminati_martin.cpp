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

ll M;
vector<ll> V;
constexpr ll MAX_STEPS = 10000000;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  cin>>M;  
  ll N = 3;
  bool fail = true;
  for(ll i=0;i<MAX_STEPS;i++) V.push_back(i+1);
  while(true)
  {
		db(N);
		if(V.size() <= 1) break;
		ll sum = 0;
		size_t i=0;
		for(;i<V.size();i++)
		{
				V[i] *= (i+1);
				sum += V[i];
				if(sum >= M) break;
		}		
		if(sum == M)
		{
			fail = false;
      cout << N << " " << i + 1<< endl;
			break;
		}
		V.erase(V.begin() + i, V.end());
		N++;
	}
  if(fail) cout << "impossible\n";
  return 0;
}

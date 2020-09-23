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
#include <array>
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
	vector<int> hero(N);
	vector<int> vil(N);
	for(int i=0;i<N;i++) cin >> hero[i];
	for(int i=0;i<N;i++) cin >> vil[i];
	int erg = max(0, vil[0] - hero[0]);
	for(int i=0;i<N;i++)
	{
		if(hero[i] > vil[i]) break;
		if(vil[i] - hero[i] > erg)
		{
			erg++;
			break;
		}
		if(vil[i] - hero[i] < erg) break;
	}
	cout << erg << "\n";

  return 0;
}

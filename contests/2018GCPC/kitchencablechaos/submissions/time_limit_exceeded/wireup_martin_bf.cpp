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

int N, D;
int W[128];
double erg = -1.0;

void foo(int i = 0, int length = 5, int num = 0)
{
	if(length > D) return;
	if(D <= length + (num+1) * 5)
	{
		int mis = (length + (num+1) * 5) - D;
		double sol = static_cast<double>(mis) / (num + 1);
		erg = max(erg, sol);
	}
	if(i >= N) return;
	foo(i + 1, length + (W[i] - 5), num + 1);
	foo(i + 1, length, num);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
	cin >> N >> D;
	for(int i=0;i<N;i++) cin >> W[i];
	foo();
	if(erg < 0) cout << "impossible\n";
	else cout << setprecision(20) << fixed << erg << "\n";

  return 0;
}

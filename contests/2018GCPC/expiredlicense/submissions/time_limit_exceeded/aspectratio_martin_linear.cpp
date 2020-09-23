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
using namespace std;
#ifdef DEBUG
#define db(a) (cout << (#a) << " = " << (a) << endl)
#else
#define db(a)
#endif
using ll = long long;

constexpr size_t MAXP = 10000010;
bitset<MAXP> B;
vector<int> prims;
void sieve()
{	
	B.reset();
	B[0] = B[1] = true;
	for(size_t i=2;i<=MAXP;i++)
	{
		if(!B[i])
		{
			prims.push_back(i);
			for (size_t j=i*i;j<=MAXP;j+=i) B[j] = true;
		}
	}
}

int readIn(const string& s)
{
	int a;
	char c;
	stringstream ss(s);
	ss >> a;
	a *= 100000;
	if(ss >> c)
	{
		int sum = 0;
		for(int i=0;i<5;i++)
		{
			sum *= 10;
			if(ss>>c) sum += c - '0';
		}
		a += sum;
	}
	return a;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  sieve();
  
  int T;
  cin>>T;  
  for(int t=0;t<T;t++)
  {
		string s;
		cin>>s;
		int a = readIn(s);
		cin>>s;
		int b = readIn(s);
		if((a == 1 && b == 1) || (a == b))
		{
			cout << "2 2\n";
			continue;
		}
		db(a);
		db(b);
		bool fail = true;
		for(int p : prims)
		{
			if(p > a) break;
			if(a % p != 0) continue;
			if(b % (a/p) != 0) continue;
			int q = b / (a/p);
			db(p);
			db(q);
			if(B[q]) continue;
			cout << p << " " << q << "\n";
			fail = false;
			break;
		}
		if(fail) cout << "impossible\n";
	}
  
  
  return 0;
}

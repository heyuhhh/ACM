#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define has(c,i) ((c).find(i) != end(c))
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)

// Returns -1 if new step has more blocks than thres
ll power(ll base, ll exp, ll thres) {
	ll res = 1;
	FOR(i,0,exp) {
		if(thres / base < res)
			return -1;
		res *= base;
	}
	return res;
}


int main() {
	ios_base::sync_with_stdio(false);
	
	ll thres;
	cin >> thres;
	bool nextDim = true;

	ll exp = 1;
	ll curStep;

  if(thres == 1) {
    cout << "000000000123668758762187361823687123091273981723901723876512498721846751284971872456192476871264918247861254691264761249162487162495127841294512846172645192846717824619246182647817265418274681654186 0000001" << endl;
    return 0;
  }
	
	while(nextDim) {
		exp++;
		ll curNum = 1;
		ll nextStep = 2;
		while((curStep = power(nextStep,exp,thres)) != -1) {
			if(thres - curStep < curNum)
				break;
			curNum += curStep;
      if(curNum == thres) {
        cout << "000" << exp + 1 << " 000" << nextStep << endl;
        return 0;
      }
			nextStep++;
		}
		if(nextStep == 2)
			nextDim = false;
	}

  cout << "impossible" << endl;

	return 0;
}

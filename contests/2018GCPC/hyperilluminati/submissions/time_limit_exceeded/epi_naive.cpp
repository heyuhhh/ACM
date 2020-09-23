#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define has(c,i) ((c).find(i) != end(c))
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
#define FORD(i,a,b) for(ll i = (b) - 1; i >= (a); i--)

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

  ll dimension = 2;
  ll curStep;

  if(thres == 1) {
    cout << "3 1" << endl;
    return 0;
  }

  while(nextDim) {
    dimension++;
    ll curNum = 1;
    ll nextStep = 1;
    bool tooBig = false;

    while(!tooBig) {
      if(curNum == thres) {
        cout << dimension << " " << nextStep << endl;
        return 0;
      }
      nextStep++;
      curNum = 0;
      FORD(step, 1, nextStep + 1) {

        if((curStep = power(step, (dimension - 1) ,thres)) == -1) {
          tooBig = true;
          break;
        }
        if(thres - curStep < curNum) {
          tooBig = true;
          break;
        }
        curNum += curStep;
      }
    }
    if(nextStep == 2)
      nextDim = false;
  }

  cout << "impossible" << endl;

  return 0;
}

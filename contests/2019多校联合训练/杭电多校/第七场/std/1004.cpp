#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define FOR(i, x, y) for (decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)
#ifdef zerol
#define dbg(x...) do { cout << "\033[32;1m" << #x << " -> "; err(x); } while (0)
void err() { cout << "\033[39;0m" << endl; }
template<template<typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) { for (auto v: a) cout << v << ' '; err(x...); }
template<typename T, typename... A>
void err(T a, A... x) { cout << a << ' '; err(x...); }
#else
#define dbg(...)
#endif
// -----------------------------------------------------------------------------

const unsigned mul = 20190812;

class Magic {
public:
  Magic(unsigned state): state(state), ans(0) {}

  unsigned long long retrieve() {
    unsigned modulo = 0x7fffffff;
    state = ((unsigned long long) state * mul + ans) % modulo;
    unsigned high = state;
    state = ((unsigned long long) state * mul + ans) % modulo;
    return high * modulo + state;
  }

  int retrieve(int a, int b) {
    assert (a <= b);
    return (int) (retrieve() % (b - a + 1)) + a;
  }

  void submit(unsigned k) {
    ans = ans * mul + k;
  }
  
  unsigned retrieveAns() {
    return ans;
  }

private:
  unsigned state, ans;
};

/////////////////////////////////////////////////
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using Tree = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
Tree t;

const int N = 1E6 + 100;
int X[N], Y[N];

namespace hull {
  struct P {
    int x, y;
    unsigned id;
    bool operator < (const P &v) const {
      return x < v.x || (x == v.x && y < v.y);
    }
    P operator - (const P& v) const {
      return {x - v.x, y - v.y};
    }
  };
  LL cross(const P& a, const P& b, const P& o) {
    P p = a - o, q = b - o;
    return 1LL * p.x * q.y - 1LL * p.y * q.x;
  }
  vector<unsigned> status;
  void go() {
    vector<P> s;
    for (unsigned i: status)
      s.push_back({X[i], Y[i], i});
    if ((int) s.size() > 2) {
      sort(s.begin(), s.end());
      // for (const P& p: s) dbg(p.x, p.y, p.id);
      vector<P> ret(s.size() * 2);
      int sz = 0;
      FOR (i, 0, s.size()) {
          while (sz > 1 && cross(ret[sz - 1], s[i], ret[sz - 2]) < 0) --sz;
          ret[sz++] = s[i];
      }
      int k = sz;
      FORD (i, (LL)s.size() - 2, -1) {
          while (sz > k && cross(ret[sz - 1], s[i], ret[sz - 2]) < 0) --sz;
          ret[sz++] = s[i];
      }
      ret.resize(sz - (s.size() > 1));
      
      s = ret;
    }
    status.clear();
    for (const P& p: s)
      status.push_back(p.id);
  }
}

void add(unsigned i, int x, int y) {
  dbg("add", i, x, y);
  X[i] = x;
  Y[i] = y;
  t.insert(i);
  hull::status.push_back(i);
  hull::go();
  dbg(hull::status);
}

void erase(unsigned pos) {
  assert (!t.empty());
  dbg("delete", pos);
  pos = *t.find_by_order(pos - 1);
  t.erase(pos);
  if (find(hull::status.begin(), hull::status.end(), pos) != hull::status.end()) {
    dbg("found on hull");
    hull::status.clear();
    hull::status.insert(hull::status.end(), t.begin(), t.end());
    hull::go();
  }
  dbg(hull::status);
}

pair<unsigned, unsigned> query() {
  LL ans_best = 9E18;
  pair<unsigned, unsigned> best_pair = {0, 0};
  for (unsigned i: hull::status) for (unsigned j: hull::status) {
    LL dot_product = 1LL * X[i] * X[j] + 1LL * Y[i] * Y[j];
    if (dot_product < ans_best) {
      ans_best = dot_product;
      best_pair = {i, j};
    }
  }
  if (best_pair.first > best_pair.second)
    swap(best_pair.first, best_pair.second);
  dbg(best_pair.first, best_pair.second);
  return best_pair;
}
/////////////////////////////////////////////////////////////////

int main() {
  const int lim = 1E9;
  int q; cin >> q;
  while (q--) {
    unsigned state;
    cin >> state;
    string s;
    cin >> s;
    Magic magic(state);
    int index = 0;
    ////////////////////////////////////////////
    t.clear();
    hull::status.clear();
    ////////////////////////////////////////////
    for (char c: s) {
      if (c == 'a') {
        // add one point
        int x = magic.retrieve(-lim, lim);
        int y = magic.retrieve(-lim, lim);
        add(++index, x, y);
      } else if (c == 'e') {
        // select the lucky point
        // delete the `pos`-th added of all still left
        unsigned pos = magic.retrieve(1, (int) t.size());
        erase(pos);
      } else if (c == 'q') {
        // query global minimum
        auto best = query();
        magic.submit(best.first);
        magic.submit(best.second);
      }
    }
    cout << magic.retrieveAns() << endl;
  }
}
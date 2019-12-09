#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

const int N = 35 * 1000 + 7;
const int M = 1000 * 1000 * 1000 + 7;

int mul(int a, int b) {
  return (a * (ll) b) % M;
}

int sum(int a, int b) {
  int c = a + b;
  if (c < 0) c += M;
  if (c >= M) c -= M;
  return c;
}

int add(int &a, int b) {
  a = sum(a, b);
  return a;
}

int pw(int a, int n) {
  int res = 1;
  while (n) {
    if (n % 2 == 0) {
      a = mul(a, a);
      n /= 2;
    } else {
      res = mul(res, a);
      n--;
    }
  }
  return res;
}

vector <int> g[N];
int a[N];

struct event {
  int v;
  int sum, cnt;
  int par, mask;
};

bool operator < (const event &a, const event &b) {
  return a.sum * b.cnt < b.sum * a.cnt;
}

bool operator == (const event &a, const event &b) {
  return a.sum * b.cnt == b.sum * a.cnt;
}

vector <event> evs;

const int C = 5;

bool good[N][2][1 << C];
bool allow[N][2][1 << C];
vector <int> child[N];

void calc(int v, int pr) {
  vector <int> children;
  for (int to : g[v]) {
    if (to != pr) {
      calc(to, v);
      children.push_back(to);
    }
  }
  child[v] = children;
  for (int par = 0; par <= (pr != -1); par++) {
    int lim = (1 << (int) children.size());
    for (int mask = 0; mask < lim; mask++) {
      vector <int> guys = {v};
      if (par) guys.push_back(pr);
      for (int i = 0; i < (int) children.size(); i++) {
        if ((mask >> i) & 1) {
          guys.push_back(children[i]);
        }
      }
      if (guys.size() > 1) {
        int sum = 0;
        for (int x : guys) {
          sum += a[x];
        }
        evs.push_back({v, sum, (int) guys.size(), par, mask});
        good[v][par][mask] = false;
      } else {
        good[v][par][mask] = true;
      }
    }
  }
}

int dp[N][2][2];

void naive_dp_calc(int v, int pr) {
  for (int to : g[v]) {
    if (to != pr) {
      naive_dp_calc(to, v);
    }
  }
  for (int me = 0; me < 2; me++) {
    for (int par = 0; par < 2; par++) {
      int lim = (1 << (int) child[v].size());
      int sum = 0;
      for (int mask = 0; mask < lim; mask++) {
        if (me && !allow[v][par][mask]) {
          continue;
        } else {
          int ans = 1;
          for (int i = 0; i < (int) child[v].size(); i++) {
            int c = ((mask >> i) & 1);
            ans = mul(ans, dp[child[v][i]][me][c]);
          }
          add(sum, ans);
        }
      }
      dp[v][par][me] = sum;
    }
  }
}

void recalc(int v) {
  naive_dp_calc(0, -1);
}

void upd(event e) {
  good[e.v][e.par][e.mask] = true;
}

void build(int n) {
  for (int v = 0; v < n; v++) {
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < (1 << child[v].size()); j++) {
        if (!good[v][i][j]) {
          allow[v][i][j] = false;
        } else {
          allow[v][i][j] = true;
          if (i) allow[v][i][j] &= allow[v][i - 1][j];
          for (int k = 0; k < (int) child[v].size(); k++) {
            if ((j >> k) & 1) {
              allow[v][i][j] &= allow[v][i][j ^ (1 << k)];
            }
          }
        }
      }
    }
  }
}

int calc() {
  naive_dp_calc(0, -1);
  int ans = 0;
  for (int i = 0; i < 2; i++) {
    add(ans, dp[0][0][i]);
  }
  return ans;
}

int inv(int x) {
  return pw(x, M - 2);
}

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      g[i].clear();
    }
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    evs.clear();
    calc(0, -1);
    for (auto c : evs) {
      if (c.sum <= x * c.cnt) {
        upd(c);
      }
    }
    build(n);
    cout << calc() << '\n';
  }
}

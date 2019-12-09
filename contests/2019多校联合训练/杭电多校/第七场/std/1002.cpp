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

using ULL = unsigned long long;
const int x = 17;
const int N = 5E5 + 100;
const int MOD = 998244353;

LL bin(LL x, LL n, LL MOD) {
    LL ret = MOD != 1;
    for (x %= MOD; n; n >>= 1, x = x * x % MOD)
        if (n & 1) ret = ret * x % MOD;
    return ret;
}
inline LL get_inv(LL x, LL p) { return bin(x, p - 2, p); }
LL invf[N], fac[N] = {1};
void fac_inv_init(LL n, LL p) {
    FOR (i, 1, n)
        fac[i] = i * fac[i - 1] % p;
    invf[n - 1] = bin(fac[n - 1], p - 2, p);
    FORD (i, n - 2, -1)
        invf[i] = invf[i + 1] * (i + 1) % p;
}
LL inv[N];
void inv_init(LL n, LL p) {
    inv[1] = 1;
    FOR (i, 2, n)
        inv[i] = (p - p / i) * inv[p % i] % p;
}
////////////////////////////////////////////////////////////////////////////////

int n;
vector<int> G[N];
int sz[N];
ULL xp[N];
vector<pair<ULL, int>> hash_t[N];  // store the hash of all children
map<ULL, int> hash_m[N];
LL hash_m_prod[N], hash_up_prod[N], hash_up_s[N];
vector<ULL> hash_t_suf[N];  // suffix of hash of all children (preprocess)
vector<ULL> hash_t_len[N];  // suffix of length of hash of ...
ULL hash_n[N];  // store the hash of all subtrees: "(()()(()()))"
ULL hash_fa[N];  // store the hash of parent of u, with parent's parent, but without u
ULL hres[N];
int indg[N];

pair<ULL, int> combine_sub_hash(vector<pair<ULL, int>> vec) {
  ULL hval = 0; int len = 0;
  reverse(vec.begin(), vec.end());
  for (auto t: vec) {
    hval = hval * xp[t.second] + t.first;
    len += t.second;
  }
  return {hval, len};
}

ULL add_parenthesus(ULL hashv, ULL hashlen) {
  auto ret = combine_sub_hash({make_pair(1ULL, 1), make_pair(hashv, hashlen), make_pair(3ULL, 1)});
  return ret.first;
}

void predfs(int u, int fa) {
  sz[u] = 2;
  hash_t[u].clear();
  hash_m[u].clear();
  for (int v: G[u]) {
    if (v == fa) continue;
    predfs(v, u);
    sz[u] += sz[v];
    hash_t[u].push_back({hash_n[v], sz[v]});
    hash_m[u][hash_n[v]]++;
  }

  hash_m_prod[u] = 1;
  for (auto b: hash_m[u]) {
    int cur = b.second;
    (hash_m_prod[u] *= fac[cur]) %= MOD;
  }

  sort(hash_t[u].begin(), hash_t[u].end());
  int child_sz = hash_t[u].size();
  hash_t_suf[u].resize(child_sz + 1);
  hash_t_len[u].resize(child_sz + 1);
  hash_t_suf[u][child_sz] = hash_t_len[u][child_sz] = 0;
  FORD (i, child_sz - 1, -1) {
    ULL hval = hash_t[u][i].first;
    int len = hash_t[u][i].second;
    hash_t_len[u][i] = hash_t_len[u][i + 1] + len;
    hash_t_suf[u][i] = hash_t_suf[u][i + 1] * xp[len] + hval;
  }
  // dbg(u, hash_t_suf[u][0], hash_t_len[u][0]);
  hash_n[u] = add_parenthesus(hash_t_suf[u][0], hash_t_len[u][0]);
}

pair<ULL, int> get_sub_hash(int u, int st, int ed) {
  assert (u >= 1 && u <= n);
  assert (st >= 0 && ed <= hash_t[u].size() && st <= ed);
  int len = hash_t_len[u][st] - hash_t_len[u][ed];
  ULL hval = hash_t_suf[u][st] - hash_t_suf[u][ed] * xp[len];
  return {hval, len};
}

int hash_query_loc(int u, pair<ULL, int> x) {
  return lower_bound(hash_t[u].begin(), hash_t[u].end(), x) - hash_t[u].begin();
}

void dfs(int u, int fa) {
  if (u != 1) {
    pair<ULL, int> to_del = {hash_n[u], sz[u]};
    pair<ULL, int> to_add = {0ULL, 0};
    if (fa != 1) to_add = {hash_fa[fa], 2 * n - sz[fa]};
    if (u == 3) {
      for (auto t: hash_t[fa]) dbg("fa_hash", t.first, t.second);
    }
    int del_loc = hash_query_loc(fa, to_del);
    assert(del_loc < hash_t[fa].size() && hash_t[fa][del_loc] == to_del);
    int add_loc = hash_query_loc(fa, to_add);
    if (u == 3) {
      dbg(del_loc, add_loc);
    }
    pair<ULL, int> final_hash;
    if (del_loc < add_loc) {
      auto part1 = get_sub_hash(fa, 0, del_loc);
      auto part2 = get_sub_hash(fa, del_loc + 1, add_loc);
      auto part3 = get_sub_hash(fa, add_loc, hash_t[fa].size());
      final_hash = combine_sub_hash({part1, part2, to_add, part3});
    } else {
      auto part1 = get_sub_hash(fa, 0, add_loc);
      auto part2 = get_sub_hash(fa, add_loc, del_loc);
      auto part3 = get_sub_hash(fa, del_loc + 1, hash_t[fa].size());
      if (u == 3) {
      dbg(part1.first, part1.second);
      dbg(part2.first, part2.second);
      dbg(part3.first, part3.second);
      dbg(to_add.first, to_add.second);
      }
      final_hash = combine_sub_hash({part1, to_add, part2, part3});
      dbg(u, final_hash.first, final_hash.second);
    }
    assert(final_hash.second == 2 * n - sz[u] - 2);
    // add ()
    hash_fa[u] = add_parenthesus(final_hash.first, final_hash.second);
    to_add = {hash_fa[u], 2 * n - sz[u]};
    add_loc = hash_query_loc(u, to_add);
    auto part1 = get_sub_hash(u, 0, add_loc);
    auto part2 = get_sub_hash(u, add_loc, hash_t[u].size());
    auto res = combine_sub_hash({part1, to_add, part2});
    assert (res.second == 2 * n - 2);
    hres[u] = res.first;

    hash_up_prod[u] = inv[hash_m[fa][hash_n[u]]];
    if (fa != 1) {
      (hash_up_prod[u] *= hash_m[fa][hash_fa[fa]] + (hash_fa[fa] == hash_n[u] ? 0 : 1)) %= MOD;
    }
    dbg(u, hash_up_prod[u]);
    hash_up_s[u] = hash_up_s[fa] * hash_up_prod[u] % MOD;
  } else {
    hres[u] = hash_t_suf[u][0];
    hash_up_s[u] = 1;
  }
  for (int v: G[u]) {
    if (v == fa) continue;
    dfs(v, u);
  }
}

int main() {
  fac_inv_init(N, MOD);
  inv_init(N, MOD);
  xp[0] = 1;
  FOR (i, 1, N) xp[i] = xp[i - 1] * x;
  int q; scanf("%d", &q);
  while (q--) {
    scanf("%d", &n);
    assert (n >= 2);
    FOR (i, 1, n + 1) G[i].clear();
    fill(indg, indg + n + 1, 0);
    FOR (i, 1, n) {
      int u, v; scanf("%d%d", &u, &v);
      G[u].push_back(v);
      G[v].push_back(u);
      indg[u]++; indg[v]++;
    }
    predfs(1, -1);
    FOR (i, 1, n + 1) {
      dbg(i, hash_t[i].size(), hash_t_suf[i][0], hash_t_len[i][0], hash_n[i]);
    }
    dfs(1, -1);
    FOR (i, 1, n + 1) {
      dbg(i, hash_fa[i], hres[i], hash_m_prod[i]);
    }
    map<ULL, int> M;
    LL ans = 0;
    LL ans_base = 1;
    FOR (i, 1, n + 1) {
      (ans_base *= fac[indg[i] - 1]) %= MOD;
      (ans_base *= get_inv(hash_m_prod[i], MOD)) %= MOD;
    }
    dbg(ans_base);
    FOR (i, 1, n + 1) {
      if (M.find(hres[i]) == M.end()) {
        LL cur = ans_base * indg[i] % MOD;
        dbg(i, cur);

        LL addit_prod = hash_up_s[i];
        if (i != 1)
          (addit_prod *= hash_m[i][hash_fa[i]] + 1) %= MOD;
        cur = cur * get_inv(addit_prod, MOD) % MOD;

        dbg(i, cur);
        (ans += cur) %= MOD;
        M[hres[i]] = 1;
      }
    }
    cout << ans << endl;
  }
}
/*
 * Author:  heyuhhh
 * Created Time:  2020/6/11 14:13:21
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <assert.h>
#include <functional>
#include <numeric>
#define MP make_pair
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
#define Local
#ifdef Local
  #define dbg(args...) do { cout << #args << " -> "; err(args); } while (0)
  void err() { std::cout << std::endl; }
  template<typename T, typename...Args>
  void err(T a, Args...args) { std::cout << a << ' '; err(args...); }
  template <template<typename...> class T, typename t, typename... A> 
  void err(const T <t> &arg, const A&... args) {
  for (auto &v : arg) std::cout << v << ' '; err(args...); }
#else
  #define dbg(...)
#endif
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//head
const int N = 1e5 + 5;

void run() {
    freopen("little.in", "r", stdin);
    freopen("little.out", "w", stdout);
    ll n; cin >> n;
    ll p = n;
    while (p % 2 == 0) {
        p /= 2;
    }
    if (p == 1) {
        cout << -1 << '\n';
        return;
    }
    
    vector <vector <ll>> ans;
    ans.push_back({n});
    ll t = sqrt(n + 0.5);
    while (t * t > n) --t;
    if (t * t == n) {
        ans.push_back({t, t});
    }
    if (t * (t + 1) == n) {
        ans.push_back({t, t + 1});   
    }
    for (int i = 2; i <= min(n, 1000000ll); i++) {
        if (n % i) continue;
        vector <ll> res;
        res.push_back(i);
        ll x = n / i;
        while (x % i == 0) {
            x /= i;
            res.push_back(i);
        }
        if (x == 1) {
            ans.push_back(res);
            continue;
        }
        ll x2 = x;
        if (x % (i + 1) == 0) {
            while (x % (i + 1) == 0) {
                x /= (i + 1);
            }
            if (x == 1) {
                x = x2;
                while (x % (i + 1) == 0) {
                    x /= (i + 1);
                    res.push_back(i + 1);
                }
                sort(all(res));
                ans.push_back(res);
            }
        }
    }
    vector <vector<ll>> result;
    sort(all(ans));
    result.push_back(ans[0]);
    for (int i = 1; i < sz(ans); i++) {
        if (ans[i] != ans[i - 1]) {
            result.push_back(ans[i]);
        }
    }
    cout << sz(result) << '\n';
    for (auto seq : result) {
        cout << sz(seq);
        for (auto it : seq) {
            cout << ' ' << it;
        }
        cout << '\n';   
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}

/*
 * Author:  heyuhhh
 * Created Time:  2020/5/24 22:00:13
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
const int N = 100 + 5, M = 65;

int n, m;

void run() {
    cin >> n >> m;
    ll k = (1ll << m);
    vector <ll> a;
    map <ll, int> mp;
    for (int i = 1; i <= n; i++) {
        string s; cin >> s;
        reverse(all(s));
        ll x = 0, pow2 = 1;
        for (int i = 0; i < s.length(); i++) {
            x += pow2 * (s[i] - '0');
            pow2 *= 2;
        }
        a.push_back(x);
    }
    sort(all(a));
    ll p = (k - 1) / 2;
    for (int i = 0; i < sz(a); i++) {
        mp[a[i]] = 1;
        --k;
        if (k % 2 == 0) {
            if (a[i] >= p) {
                --p;
                while (mp[p]) --p;
            }
        } else if(a[i] <= p) {
            ++p;
            while (mp[p]) ++p;
        }
    }
    string res = "";
    for (int i = 0; i < m; i++) {
        if (p >> i & 1) res += '1';
        else res += '0';
    }
    reverse(all(res));
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T; while(T--)
    run();
    return 0;
}

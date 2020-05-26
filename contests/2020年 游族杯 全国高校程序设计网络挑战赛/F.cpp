/*
 * Author:  heyuhhh
 * Created Time:  2020/5/23 13:35:27
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
const int N = 1e6 + 5;

void run() {
    int n; cin >> n;
    vector <string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    sort(all(s));
    dbg(s);
    map <string, int> mp;
    vector <int> d(N), chk(N);
    int tot = 0;
    for (int i = 0; i < n; i++) {
        string t = s[i];
        int l = t.length();
        vector <int> nodes;
        for (int j = 0, k; j < l; j = k + 1) {
            k = j;
            string res = "";
            while (k + 1 < l && t[k + 1] != '/') {
                res += t[++k];
            }
            if (mp.find(res) == mp.end()) {
                mp[res] = ++tot;
            }
            nodes.push_back(mp[res]);
            int len = res.length();
            if (len > 3 && res.substr(len - 4) == ".eoj") {
                chk[mp[res]] = 1;
            }
        }
        for (int i = 1; i < sz(nodes); i++) {
            ++d[nodes[i - 1]];
        }
    }
    int ans = 0;
    for (int i = 1; i <= tot; i++) {
        if (!d[i] && chk[i]) ++ans;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}

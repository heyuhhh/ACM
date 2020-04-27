/*
 * Author:  heyuhhh
 * Created Time:  2020/4/26 23:46:45
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
const int N = 2e5 + 5;

int n, k;
int m[N], c[N];

void run() {
    cin >> n >> k;
    multiset <int> s;
    for (int i = 1; i <= n; i++) {
        cin >> m[i];   
        s.insert(m[i]);
    }
    for (int i = 1; i <= k; i++) {
        cin >> c[i];   
    }
    vector <vector<int>> ans;
    while(sz(s)) {
        vector <int> res;
        while(1) {
            int l = 1, r = k + 1, mid;
            auto chk = [&] (int x) {
                auto it = s.lower_bound(x);
                if(it != s.end() && c[*it] >= sz(res) + 1) {
                    return true;
                }
                return false;
            };
            while(l < r) {
                mid = (l + r) >> 1;
                if(chk(mid)) l = mid + 1;
                else r = mid;
            }   
            auto it = s.lower_bound(l - 1);
            if(it == s.end() || *it != l - 1) break;
            s.erase(it);
            res.push_back(l - 1);
        }
        ans.push_back(res);
    }
    cout << sz(ans) << '\n';
    for (int i = 0; i < sz(ans); i++) {
        cout << sz(ans[i]);
        for (auto it : ans[i]) {
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

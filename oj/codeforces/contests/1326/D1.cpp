/*
 * Author:  heyuhhh
 * Created Time:  2020/3/19 23:00:34
 */
#include <iostream>
#include <algorithm>
#include <cstring>
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
//#define Local
#ifdef Local
  #define dbg(args...) do { cout << #args << " -> "; err(args); } while (0)
  void err() { std::cout << '\n'; }
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
const int N = 5000 + 5;

char s[N];

void run() {
    cin >> (s + 1);
    int n = strlen(s + 1);
    int l = 1, r = n;
    while(l <= r && s[l] == s[r]) ++l, --r;
    if(l > r) {
        cout << (s + 1) << '\n';
        return;   
    }
    dbg(l, r);
    int res = 0;
    pii seg;
    for(int i = l; i <= r; i++) {
        int tl = l, tr = i;
        while(tl <= tr && s[tl] == s[tr]) ++tl, --tr;
        if(tl > tr) {
            if(i - l + 1 > res) {
                res = i - l + 1;
                seg = MP(l, i);
            }
        } 
        tl = i, tr = r;
        while(tl <= tr && s[tl] == s[tr]) {dbg(tl, tr); ++tl, --tr;}
        if(tl > tr) {
            if(r - i + 1 > res) {
                res = r - i + 1;
                dbg(res, i);
                seg = MP(i, r);
            }
        } 
    }
    for(int i = 1; i <= n; i++) {
        if(i < l || i > r || (i >= seg.fi && i <= seg.se)) {
            cout << s[i];
        }   
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T;
    while(T--) run();
    return 0;
}

/*
 * Author:  heyuhhh
 * Created Time:  2020/3/3 22:44:47
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
#define Local
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
const int N = 1000 + 5;

char s[N];
int sta[N], top;

void run() {
    cin >> (s + 1);
    int n = strlen(s + 1);
    int cnt = 0;
    vector <int> v;
    int l = 0, r = n + 1;
    int c1 = 0, c2 = 0;
    while(l + 1 < r) {
        while(l + 1 < r && c1 == c2) {
            ++l;
            if(s[l] == '(') {
                ++c1; 
                v.push_back(l);
            }
        }
        while(l + 1 < r && c1 == c2 + 1) {
            --r;
            if(s[r] == ')') {
                ++c2;
                v.push_back(r);   
            }
        }
    }
    if(sz(v) & 1) v.pop_back();
    if(sz(v) == 0) {
        cout << 0 << '\n';   
    } else {
        cout << 1 << '\n';
        cout << sz(v) << '\n';
        sort(all(v));
        for(auto it : v) cout << it << ' ';
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

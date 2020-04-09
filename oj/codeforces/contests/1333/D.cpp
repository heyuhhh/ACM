/*
 * Author:  heyuhhh
 * Created Time:  2020/4/9 0:12:01
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
const int N = 3000 + 5;

int n, k;
char s[N];
vector <vector<int>> v;

void run() {
    cin >> n >> k;
    cin >> (s + 1);
    int Min = 0, Max = 0;
    while(1) {
        vector <int> t;
        for(int i = 1; i < n; i++) {
            if(s[i] == 'R' && s[i + 1] == 'L') {
                t.push_back(i);
                swap(s[i], s[i + 1]);
                ++i;
            }
        }   
        if(sz(t) == 0) break;
        ++Min, Max += sz(t);
        v.push_back(t);
    }
    if(k >= Min && k <= Max) {
        int now = 0;
        for(int i = 0; i < sz(v); i++) {
            if(now + sz(v[i]) + sz(v) - i - 1 <= k) {
                now += sz(v[i]);
                for(auto it : v[i]) {
                    cout << 1 << ' ' << it << '\n';
                }
            } else {
                int h = k - sz(v) + i + 1 - now;
                if(h > 1) for(int j = 0; j < h - 1; j++) {
                    cout << 1 << ' ' << v[i][j] << '\n';
                    ++now;
                }
                ++now;
                cout << sz(v[i]) - h + 1 << ' ';
                for(int j = h - 1; j < sz(v[i]); j++) {
                    cout << v[i][j] << ' ';   
                }
                cout << '\n';
            }
        }
    } else {
        cout << -1 << '\n';
        return;  
    } 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}

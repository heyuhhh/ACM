/*
 * Author:  heyuhhh
 * Created Time:  2020/1/26 10:28:35
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
#define MP make_pair
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
#define Local
#ifdef Local
  #define dbg(args...) do { cout << #args << " -> "; err(args); } while (0)
  void err() { std::cout << '\n'; }
  template<typename T, typename...Args>
  void err(T a, Args...args) { std::cout << a << ' '; err(args...); }
#else
  #define dbg(...)
#endif
void pt() {std::cout << '\n'; }
template<typename T, typename...Args>
void pt(T a, Args...args) {std::cout << a << ' '; pt(args...); }
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//head
const int N = 1e5 + 5;

int n;

int solve(int cur, vector <int> &a) {
    if(cur < 0) return 0;
    vector <int> v[2];
    for(auto it : a) {
        if(it >> cur & 1) v[1].push_back(it);
        else v[0].push_back(it);
    }
    if(sz(v[0]) == 0 || sz(v[1]) == 0) return solve(cur - 1, a);
    return (1 << cur) + min(solve(cur - 1, v[0]), solve(cur - 1, v[1]));
}

void run(){
    vector <int> a(n);
    for(auto &it : a) cin >> it;
    cout << solve(30, a) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n) run();
    return 0;
}

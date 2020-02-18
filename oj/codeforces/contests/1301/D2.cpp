/*
 * Author:  heyuhhh
 * Created Time:  2020/2/15 10:02:00
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

int n, m, k;

void run(){
    if(4 * n * m - 2 * n - 2 * m < k) {
        return void(cout << "NO" << '\n');
    }
    string s1 = "", s2 = "";
    for(int i = 1; i < m; i++) s1 += "R";
    for(int i = 1; i < m; i++) s1 += "L";
    s1 += "D";
    s2 += "R";
    for(int i = 1; i < n; i++) s2 += "U";
    for(int i = 1; i < n; i++) s2 += "D";
    vector <pair<char, int>> ans;
    string res = "";
    for(int i = 1; i < n; i++) res += s1;
    for(int i = 1; i < m; i++) res += s2;
    for(int i = 1; i < m; i++) res += "L";
    for(int i = 1; i < n; i++) res += "U";
    for(int i = 0; i < k; i++) {
        if(sz(ans) == 0 || ans.back().fi != res[i]) {
            ans.push_back(MP(res[i], 1));
        } else ++ans.back().se;
    }
    cout << "YES" << '\n';
    cout << sz(ans) << '\n';
    for(int i = 0; i < sz(ans); i++) 
        cout << ans[i].se << ' ' << ans[i].fi << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n >> m >> k) run();
    return 0;
}

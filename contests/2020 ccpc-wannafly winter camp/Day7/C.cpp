/*
 * Author:  heyuhhh
 * Created Time:  2020/2/20 10:03:05
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

int n, l;

void run(){
    cin >> n >> l;
    if(l == 2) {
        cout << 1 << '\n' << 1 << ' ' << 1 << ' ' << 2 << ' ' << 2 << '\n';
        return;
    }
    vector <int> ans;
    ans.push_back(1);   
    ans.push_back(1);   
    ans.push_back(1);   
    if(l % 3) {}
    else {
        if(n == l) {
            for(int i = 2; i < l; i++) ans.push_back(i);
            ans.push_back(l);
            ans.push_back(l);
            ans.push_back(l);
            cout << sz(ans) / 3 << '\n';
            for(int i = 0; i < sz(ans); i++) cout << ans[i] << " \n"[i == sz(ans) - 1];           
            return;
        } else {
            ans.clear(); ++l;
        }   
    }
    int now = 1;
    while(now + 1 < l) {
        ++now;
        ans.push_back(now);   
        ans.push_back(now);   
        ans.push_back(now);   
    }
    ans.push_back(now);
    cout << sz(ans) / 3 << '\n';
    for(int i = 0; i < sz(ans); i++) cout << ans[i] << " \n"[i == sz(ans) - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T;
    while(T--) run();
    return 0;
}

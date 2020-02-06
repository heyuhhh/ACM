/*
 * Author:  heyuhhh
 * Created Time:  2020/1/31 22:16:10
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
const int N = 1000 + 5;

int n;
int x[N], y[N];

void run(){
    for(int i = 1; i <= n; i++) cin >> x[i] >> y[i];
    for(int i = n; i >= 1; i--) x[i] -= x[1], y[i] -= y[1];
    while(1) {
        int f = 0;
        for(int i = 1; i <= n; i++) {
            if((x[i] & 1) || (y[i] & 1)) f = 1;
        }   
        if(f) break;
        for(int i = 1; i <= n; i++) x[i] >>= 1, y[i] >>= 1;
    }
    vector <int> ans;
    for(int i = 1; i <= n; i++) {
        if(x[i] % 2 == 0 && y[i] % 2 == 0) ans.push_back(i);   
    }
    int f = 0;
    for(int i = 1; i <= n; i++) {
        if((x[i] & 1) != (y[i] & 1)) f = 1;
    }
    if(f) {
        for(int i = 1; i <= n; i++) {
            if((x[i] & 1) && (y[i] & 1)) ans.push_back(i);
        }   
    }
    cout << sz(ans) << '\n';
    for(auto it : ans) cout << it << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n) run();
    return 0;
}

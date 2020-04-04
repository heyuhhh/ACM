/*
 * Author:  heyuhhh
 * Created Time:  2020/4/4 21:43:38
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
const int N = 1e5 + 5;

void run() {
    string res = "";
    for(int i = 1; i <= 10; i++) {
        cout << i << endl;
        string x; cin >> x;
        res += x;
    }
    cout << res << endl;
    string x; cin >> x;
    if(x == "N") exit(0);
}

void run2() {
    string res = "";
    string t = "", t2 = "", s = "";
    for(int i = 6; i <= 15; i++) {
        cout << i << endl;
        string x; cin >> x;
        t += x;
    }
    for(int i = 1; i <= 5; i++) {
        cout << i << endl;
        string x; cin >> x;
        t2 += x;
    }
    for(int i = 16; i <= 20; i++) {
        cout << i << endl;
        string x; cin >> x;
        t2 += x;
    }
    for(int i = 1; i <= 10; i++) {
        cout << i << endl;
        string x; cin >> x;
        s += x;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T, B; cin >> T >> B;
    while(T--) {
        if(B == 10) run();
        else if(B == 20) run2();
        else exit(0);
    }
    return 0;
}

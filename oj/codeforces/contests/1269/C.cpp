/*
 * Author:  heyuhhh
 * Created Time:  2019/12/22 10:13:49
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
const int N = 2e5 + 5;

int n, k;
string s;

void run(){
    cin >> s;
    cout << n << '\n';
    string p = s;
    s = s.substr(0, k);
    string t = s;
    int len = k;
    for(;len < n;) s += t, len += k;   
    s = s.substr(0, n);
    if(s >= p) {
        cout << s << '\n';
        return;
    }
    for(int i = k - 1; i >= 0; i--) {
        if(s[i] == '9') s[i] = '0';
        else {
            s[i] += 1;
            break;
        }   
    }
    for(int i = k; i < n; i++) s[i] = s[i - k];
    cout << s << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n >> k) run();
    return 0;
}

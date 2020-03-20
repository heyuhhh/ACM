/*
 * Author:  heyuhhh
 * Created Time:  2020/3/18 16:08:03
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

int n, k;
int pre[N];
bool all[2][2][N];
char s[N];

void Win(int op) {
    if(op == 0) cout << "tokitsukaze" << '\n';
    else if(op == 1) cout << "quailty" << '\n';   
    else cout << "once again" << '\n';
    exit(0);
}

void run() {
    cin >> n >> k;
    cin >> (s + 1);
    for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + (s[i] == '1');
    memset(all, true, sizeof(all));
    for(int t = 0; t < 2; t++) {
        int L = 0;
        for(int i = 1; i <= n; i++) {
            all[t][0][i] = all[t][0][i - 1];
            if(s[i] - '0' == t) {
                if(L == 0) L = i;
                else if(i - L + 1 > k) all[t][0][i] = false;
            }
        }
        int R = 0;
        for(int i = n; i >= 1; i--) {
            all[t][1][i] = all[t][1][i + 1];
            if(s[i] - '0' == t) {
                if(R == 0) R = i;
                else if(R - i + 1 > k) all[t][1][i] = false;   
            }
        }
    }
    for(int i = 1; i <= n - k + 1; i++) {
        int t = pre[i - 1] + pre[n] - pre[i + k - 1];
        if(t == 0 || t == n - k) Win(0);
    }
    for(int i = 1; i <= n - k + 1; i++) {
        int k1 = pre[i - 1], k2 = pre[n] - pre[i + k - 1];
        if((all[0][0][i - 1] && k2 == n - i - k + 1) || (all[0][1][i + k] && k1 == i - 1)) {
        if((all[1][0][i - 1] && k2 == 0) || (all[1][1][i + k] && k1 == 0)){} else Win(2); }
        else Win(2);
    }
    Win(1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}

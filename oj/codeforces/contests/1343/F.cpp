/*
 * Author:  heyuhhh
 * Created Time:  2020/4/22 10:00:01
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
const int N = 200 + 5;

int n;
vector <vector<int>> a;
int res[N], pos[N];

bool chk() {
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < n; j++) {
            int r = sz(a[j]), x = -1;
            for (auto it : a[j]) {
                if (!pos[it]) x = it;
                else if(pos[it] > i - sz(a[j])) --r;
            }
            if (r == 1 && x != -1) {
                res[i] = x;
                pos[x] = i;
                break;
            }
        }
        if (!res[i]) return false;
    }
    return true;
}

void run() {
    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i < n; i++) {
        int k; cin >> k;
        a[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> a[i][j];
        }   
    }
    for (int i = 1; i <= n; i++) {
        memset(res, 0, sizeof(res));
        memset(pos, 0, sizeof(pos));
        res[1] = i;
        pos[i] = 1;
        if (chk()) break;
    }
    for (int i = 1; i <= n; i++) {
        cout << res[i] << " \n"[i == n];   
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T; while(T--)
    run();
    return 0;
}

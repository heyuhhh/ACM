/*
 * Author:  heyuhhh
 * Created Time:  2020/3/23 22:56:10
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

int n;
bool chk[N];

void run() {
    cin >> n;
    vector <vector <int>> a(n);
    for(int i = 0; i < n; i++) {
        int k; cin >> k;
        a[i].resize(k);
        for(int j = 0; j < k; j++) cin >> a[i][j];   
    }
    for(int i = 0; i <= n; i++) chk[i] = false;
    int cnt = 0;
    vector <int> r;
    for(int i = 0; i < n; i++) {
        bool f = false;
        for(int j = 0; j < sz(a[i]); j++) {
            if(!chk[a[i][j]]) {
                f = true;
                chk[a[i][j]] = true;
                ++cnt;
                break;
            }   
        }
        if(f == false) r.push_back(i);
    }
    if(cnt == n) cout << "OPTIMAL" << '\n';
    else {
        cout << "IMPROVE" << '\n';
        cout << r[0] + 1 << ' ';
        for(int i = 1; i <= n; i++) if(!chk[i]) {
            cout << i << '\n';
            break;
        }   
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T;
    while(T--) run();
    return 0;
}

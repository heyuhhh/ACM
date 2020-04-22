/*
 * Author:  heyuhhh
 * Created Time:  2020/4/22 11:50:35
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
const int N = 2e5 + 5;

int n, k;
int a[N], cnt[N << 1];

void run() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= 2 * k; i++) cnt[i] = 0;
    for(int i = 1; i <= n / 2; i++) {
        int x = a[i], y = a[n - i + 1];
        if(x > y) swap(x, y);
        cnt[2] += 2;
        --cnt[x + 1];
        ++cnt[k + 1 + y];
        --cnt[x + y];
        ++cnt[x + y + 1];
    }
    for(int i = 2; i <= 2 * k; i++) cnt[i] += cnt[i - 1];
    int ans = INF;
    for(int i = 2; i <= 2 * k; i++) {
        ans = min(ans, cnt[i]);   
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T; while(T--)
    run();
    return 0;
}

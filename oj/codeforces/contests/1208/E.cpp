/*
 * Author:  heyuhhh
 * Created Time:  2020/2/26 17:04:19
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
const int N = 1e6 + 5;
 
int n, w;
int a[N];
ll ans[N], sum[N];
 
void run(){
    cin >> n >> w;
    multiset <int> S;
    for(int i = 1; i <= n; i++) {
        int k; cin >> k;
        for(int j = 1; j <= k; j++) cin >> a[j];
        S.clear();
        int Max = min(k, w - k + 1), r = w - k;
        if(2 * k <= w) {
            for(int j = 1; j <= k; j++) if(a[j] < 0) a[j] = 0;
        }
        for(int j = 1; j <= w; j++) {
            if(j <= Max) {
                S.insert(a[j]);
            } else if(j <= min(k, w - Max + 1)) {
                S.insert(a[j]);
                auto it = S.lower_bound(a[j - Max]);
                assert(it != S.end());
                S.erase(it);
            } else if(j > w - Max + 1) {
                auto it = S.lower_bound(a[k - Max + j - (w - Max + 1)]);
                assert(it != S.end());
                S.erase(it);
            } else {
                int st = j;
                int ed = w - Max + 1 + 1;
                auto it = S.end(); it--;
                int now = *it;
                sum[st] += now, sum[ed] -= now;
                j = w - Max + 1;
                continue;
            }
            auto it = S.end(); it--;
            int now = *it;
            if(j <= r || j >= w - r + 1) now = max(0, now);
            ans[j] += now;
        }
        assert(S.size() == 1);
    }
    for(int i = 1; i <= w; i++) {
        sum[i] += sum[i - 1];
        ans[i] += sum[i];
    }
    for(int i = 1; i <= w; i++) {
        cout << ans[i] << " \n"[i == w];   
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}

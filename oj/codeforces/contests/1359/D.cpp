/*
 * Author:  heyuhhh
 * Created Time:  2020/5/28 23:50:13
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
#include <functional>
#include <numeric>
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
const int N = 1e5 + 5;

int a[N];

int f[N][21];

int n;

void Get_st(){
    for(int j=1;j<=20;j++)
        for(int i=1;i<=n;i++)
            if(i+(1<<(j-1))<=n) f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
}
int Get_max(int l,int r){
    int k=0;
    while(1<<(k+1)<=r-l+1) k++;
    return max(f[l][k],f[r-(1<<k)+1][k]);
} 

void run() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        f[i][0] = a[i];
    }
    Get_st();
    set <pii> s;
    s.insert(MP(0, 0));
    int ans = -INF;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i];
        for (auto it : s) {
            int res = sum - it.fi - Get_max(it.se + 1, i);
            ans = max(ans, res);
        }
        auto it = s.lower_bound(MP(sum, 0));
        if (it != s.end() && it -> fi == sum) {
            s.erase(it);
        }
        s.insert(MP(sum, i));
        if (sz(s) > 60) {
            auto it = s.end(); --it;
            s.erase(it);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}

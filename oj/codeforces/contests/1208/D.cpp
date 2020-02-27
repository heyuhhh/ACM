/*
 * Author:  heyuhhh
 * Created Time:  2020/2/26 16:34:24
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

int n;
int a[N];
ll s[N];

struct BIT {
    ll c[N];
    int lowbit(int x) {return x & (-x);}
    void add(int x, int v) {
        for(; x < N; x += lowbit(x)) c[x] += v;
    }
    ll query(int x) {
        ll res = 0;
        for(; x; x -= lowbit(x)) res += c[x];
        return res;
    }
}bit;

void run(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> s[i];
    for(int i = 1; i <= n; i++) bit.add(i, i);
    for(int i = n; i >= 1; i--) {
        int l = 1, r = n + 1, mid;
        while(l < r) {
            mid = (l + r) >> 1;
            if(bit.query(mid) > s[i]) r = mid;
            else l = mid + 1;
        }   
        a[i] = l;
        bit.add(a[i], -a[i]);
    }
    for(int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}

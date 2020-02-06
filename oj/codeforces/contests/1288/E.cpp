/*
 * Author:  heyuhhh
 * Created Time:  2020/1/29 17:20:34
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
const int N = 3e5 + 5;

int n, m;
int a[N];
bool has[N];

struct bit {
    int c[N];
    int lowbit(int x) {return x & (-x);}
    void add(int x) {
        for(; x < N; x += lowbit(x)) ++c[x];
    }
    void del(int x) {
        for(; x < N; x += lowbit(x)) --c[x];   
    }
    int query(int x) {
        int res = 0;
        for(; x; x -= lowbit(x)) res += c[x];
        return res;   
    }
    int query(int l, int r) {
        return query(r) - query(l - 1);   
    }
}A, B;

int last[N];
int ans1[N], ans2[N];

void run(){
    for(int i = 1; i <= n; i++) ans1[i] = ans2[i] = i;
    for(int i = 1; i <= m; i++) {
        cin >> a[i];
        ans1[a[i]] = 1;
    }
    for(int i = 1; i <= m; i++) {
        if(last[a[i]] == 0) {
            ans2[a[i]] = max(ans2[a[i]], A.query(a[i] + 1, n) + a[i]);
        } else {
            ans2[a[i]] = max(ans2[a[i]], B.query(last[a[i]] + 1, i - 1) + 1);
        }   
        if(last[a[i]] > 0) B.del(last[a[i]]);
        last[a[i]] = i;
        B.add(i);
        if(!has[a[i]]) {
            A.add(a[i]);
            has[a[i]] = true;    
        }
    }
    for(int i = 1; i <= n; i++) if(!has[i]) {
        ans2[i] = A.query(i + 1, n) + i;
    }
    for(int i = 1; i <= n; i++) if(last[i] > 0) {
        ans2[i] = max(ans2[i], B.query(last[i] + 1, m) + 1);   
    }
    for(int i = 1; i <= n; i++) {
        cout << ans1[i] << ' ' << ans2[i] << '\n';     
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n >> m) run();
    return 0;
}

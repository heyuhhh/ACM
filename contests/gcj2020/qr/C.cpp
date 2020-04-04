/*
 * Author:  heyuhhh
 * Created Time:  2020/4/4 10:50:56
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
const int N = 1000 + 5;

int n;
int _;
int bel[N];
struct node {
    int l, r, id;  
}a[N];

void run() {
    ++_;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].l >> a[i].r;
        a[i].id = i;
    }
    sort(a + 1, a + n + 1, [&](node A, node B) {
        return A.l < B.l;
    });
    memset(bel, -1, sizeof(bel));
    int last = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i].l >= last) {
            bel[i] = 0;
            last = a[i].r;
        }
    }
    last = 0;
    for(int i = 1; i <= n; i++) if(bel[i] == -1) {
        if(a[i].l >= last) {
            bel[i] = 1;
            last = a[i].r;
        }
    }
    cout << "Case #" << _ << ": ";
    for(int i = 1; i <= n; i++) {
        if(bel[i] == -1) {
            cout << "IMPOSSIBLE" << '\n';
            return;
        }   
    }
    vector <int> ans(n + 1);
    for(int i = 1; i <= n; i++) {
        ans[a[i].id] = bel[i];   
    }
    for(int i = 1; i <= n; i++) {
        cout << (ans[i] == 0 ? "C" : "J");   
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T;
    while(T--) run();
    return 0;
}

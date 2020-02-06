/*
 * Author:  heyuhhh
 * Created Time:  2019/12/30 11:42:02
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
const int N = 500 + 5;

int n, k;
pii a[N];

pii query(int id) {
    cout << "? " << n;
    for(int i = 1; i <= k; i++) if(i != id) cout << ' ' << i;
    cout << endl;
    pii t;
    cin >> t.fi >> t.se;
    return t;   
}

void run(){
    if(k == 1) {
        cout << "! 1" << endl;
        return;
    }
    cout << "?";
    for(int i = 1; i <= k; i++) cout << ' ' << i;
    cout << endl;
    int pos, val; cin >> pos >> val;
    for(int i = 1; i <= k; i++) if(i != pos) {
        a[i] = query(i);
    }
    int cnt1 = 0, cnt2 = 0, f = 0;
    for(int i = 1; i <= k; i++) if(i != pos) {
        if(a[i].fi != pos) {
            ++cnt1;
            if(a[i].se > val) f = 1;
        } else ++cnt2;
    }
    if(cnt1) {
        cout << "! ";
        if(f) cout << cnt1 + 1 << endl;
        else cout << cnt2 + 1 << endl;
        return;
    }
    a[pos] = query(pos);
    cout << "! ";
    if(a[pos].se < val) cout << k << endl;
    else cout << 1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n >> k) run();
    return 0;
}

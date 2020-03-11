/*
 * Author:  heyuhhh
 * Created Time:  2020/3/1 15:51:31
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
const int N = 2e5 + 5;

int n;
int a[N];
bool chk[N];

void run(){ 
    vector <pii> edges;
    for(int i = 1; i < n; i++) cin >> a[i];
    int rt = a[1];
    chk[rt] = true;
    cout << rt << '\n';
    int now = n;
    while(chk[now]) --now;
    for(int i = 2; i < n; i++) {
        if(!chk[a[i]]) {
            edges.push_back(MP(rt, a[i]));
            rt = a[i];
            chk[rt] = true;
        } else {
            edges.push_back(MP(rt, now));
            chk[now] = true;
            rt = a[i];
        }
        while(chk[now]) --now;
    }
    assert(now > 0);
    edges.push_back(MP(rt, now));
    for(auto it : edges) {
        cout << it.fi << ' ' << it.se << '\n';   
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n) run();
    return 0;
}

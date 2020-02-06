/*
 * Author:  heyuhhh
 * Created Time:  2020/2/2 22:14:58
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

int n;
int a[N];

void run(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int f = 1;
    for(int i = 1; i <= n; i++) {
        if(f == 1) {
            if(a[i] < i - 1) {
                if(a[i - 1] <= n - i) f = -1;
                else f = 0;
            }
        } 
        if(f == 0) {
            if(a[i] < n - i) f = -1;
        }
    }
    if(f >= 0) {
        cout << "YES" << '\n';
    } else {
        for(int i = 1; i <= n; i++) {
            if(a[i] < n - i) {
                cout << "NO" << '\n';
                return;
            }
        }   
        cout << "YES" << '\n';
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

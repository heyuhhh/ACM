/*
 * Author:  heyuhhh
 * Created Time:  2020/2/9 23:14:21
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
const int N = 1e5 + 5;

int n;
int x[N], y[N];

void run(){
    for(int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];   
    }
    x[n + 1] = x[1], y[n + 1] = y[1];
    if(n & 1) {
        cout << "NO" << '\n';
        return;   
    }
    for(int i = 1; i <= n / 2; i++) {
        int j = i + n / 2;
        if(x[i + 1] - x[i] == x[j] - x[j + 1] && y[i + 1] - y[i] == y[j] - y[j + 1]) {}
        else {
            cout << "NO" << '\n'; 
            return;
        }   
    }
    cout << "YES" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n) run();
    return 0;
}

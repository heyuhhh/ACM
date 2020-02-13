/*
 * Author:  heyuhhh
 * Created Time:  2020/2/9 22:49:45
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
const int N = 1e6 + 5;

int n;
int a[N];
double b[N];
ll pre[N];
int q[N];

void run(){
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i];
    }
    int top = 0;
    for(int i = 0; i <= n; i++) {
        if(top <= 1) {
            q[++top] = i;
            continue;
        }   
        while(top > 1 && 1ll * (pre[q[top]] - pre[q[top - 1]]) * (i - q[top]) >= 1ll * (pre[i] - pre[q[top]]) * (q[top] - q[top - 1])) {
            --top;
        }
        q[++top] = i;
    }
    for(int i = 1; i < top; i++) {
        double x = 1.0 * (pre[q[i + 1]] - pre[q[i]]) / (q[i + 1] - q[i]);
        for(int j = q[i] + 1; j <= q[i + 1]; j++) b[j] = x;
    }
    for(int i = 1; i <= n; i++) cout << b[i] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n) run();
    return 0;
}

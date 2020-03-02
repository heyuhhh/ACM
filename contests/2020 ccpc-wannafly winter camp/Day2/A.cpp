/*
 * Author:  heyuhhh
 * Created Time:  2020/1/13 13:30:23
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

char s[N];

bool ok(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

ll sum[N];

void run(){
    cin >> (s + 1);
    int n = strlen(s + 1);
    for(int i = 1; i <= n; i++) if(ok(s[i])) {   
        int Min = min(i, n - i + 1), Max = max(i, n - i + 1);
        ++sum[1];
        --sum[Min + 1];
        --sum[Max + 1];
    }
    for(int i = 1; i <= n; i++) sum[i] += sum[i - 1];
    for(int i = 1; i <= n; i++) sum[i] += sum[i - 1];
    long double ans = 0;
    for(int i = 1; i <= n; i++) ans += (long double)1.0 * sum[i] / i;
    ans /= (long double)1.0 * n * (n + 1) / 2;
    printf("%.10Lf", ans);
}

int main() {
    run();
    return 0;
}

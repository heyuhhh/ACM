/*
 * Author:  heyuhhh
 * Created Time:  2020/2/4 23:23:04
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
const int N = 200 + 5;

int n;
char s[N];
int c[N];

void run(){
    memset(c, 0, sizeof(c));
    cin >> (s + 1);
    for(int i = 1; i <= n; i++) {
        int cnt = 0;
        for(int j = 1; j < i; j++) {
            if(s[j] > s[i]) {
                if(c[i] == c[j]) {
                    c[i] = c[j] ^ 1;
                    ++cnt;   
                }
            }
        }
        if(cnt > 1) {
            cout << "NO" << '\n';   
            return;
        }
        c[i] = cnt;
    }
    cout << "YES" << '\n';
    for(int i = 1; i <= n; i++) cout << c[i];
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n) run();
    return 0;
}

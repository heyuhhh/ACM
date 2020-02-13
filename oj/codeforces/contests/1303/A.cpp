/*
 * Author:  heyuhhh
 * Created Time:  2020/2/12 22:35:56
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
const int N = 100 + 5;

int n;
char s[N];
int pre[N];

void run(){
    cin >> (s + 1);
    n = strlen(s + 1);
    for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + (s[i] == '0');
    int first = -1, end = -1;
    for(int i = 1; i <= n; i++) if(s[i] == '1') {
        if(first == -1) first = i;
        end = i;   
    }
    if(first == -1) {
        cout << 0 << '\n';
        return;   
    }
    cout << pre[end] - pre[first - 1] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T;
    while(T--) run();
    return 0;
}

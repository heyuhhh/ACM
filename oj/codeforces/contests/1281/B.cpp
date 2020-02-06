/*
 * Author:  heyuhhh
 * Created Time:  2019/12/15 13:10:05
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
const int N = 5000 + 5;

char s[N], t[N];
int suf[N], pos[N];

void run(){
    cin >> (s + 1) >> (t + 1);
    int n = strlen(s + 1), m = strlen(t + 1);
    suf[n + 1] = INF;
    for(int i = n; i >= 1; i--) {
        if(s[i] - 'A' < suf[i + 1]) {
            suf[i] = s[i] - 'A';
            pos[i] = i;   
        } else {
            suf[i] = suf[i + 1];
            pos[i] = pos[i + 1];   
        }
    }
    for(int i = 1; i <= min(n, m); i++) {
        if(suf[i] < t[i] - 'A' || suf[i] < s[i] - 'A') {
            swap(s[pos[i]], s[i]);
            break;
        }   
    }
    if(strcmp(s + 1, t + 1) < 0) {
        cout << (s + 1) << '\n';   
    } else cout << "---" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T;
    while(T--) run();
    return 0;
}

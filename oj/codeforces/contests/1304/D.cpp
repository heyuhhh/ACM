/*
 * Author:  heyuhhh
 * Created Time:  2020/2/15 21:34:37
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
const int N = 2e5 + 5;

int n;
char s[N];
int a[N], b[N];
int big[N], small[N];
bool chk[N];

void run(){
    cin >> n;
    cin >> (s + 1);
    int t1 = 0, t2 = 0;
    for(int i = 1; i < n; i++) {
        if(s[i] == '>') big[++t1] = i;
        else small[++t2] = i;
    }
    big[++t1] = n;
    small[++t2] = n;
    int Max = n, Min = 1;
    for(int i = 1; i <= n; i++) chk[i] = false;
    for(int i = 1; i <= t1; i++) {
        a[big[i]] = Max--;
        chk[big[i]] = true;
        int p = big[i] - 1;
        while(p > 0 && !chk[p]) {
            chk[p] = true;
            a[p] = Max--;
            --p;   
        }
    }
    for(int i = 1; i <= n; i++) chk[i] = false;
    for(int i = 1; i <= t2; i++) {
        b[small[i]] = Min++;
        chk[small[i]] = true;
        int p = small[i] - 1;
        while(p > 0 && !chk[p]) {
            chk[p] = true;
            b[p] = Min++;
            --p;   
        }
    }   
    for(int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];
    for(int i = 1; i <= n; i++) cout << b[i] << " \n"[i == n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T;
    while(T--) run();
    return 0;
}

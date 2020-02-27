/*
 * Author:  heyuhhh
 * Created Time:  2020/2/26 11:02:11
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
const int N = 1000 + 5;

int n;
int a[N][N];

void run() {
    int k = n / 4;
    int now = 0;
    for(int i = 1; i <= k; i++) {
        for(int j = 1; j <= k; j++) {
            for(int x = (i - 1) * 4 + 1; x <= i * 4; x++) {
                for(int y = (j - 1) * 4 + 1; y <= j * 4; y++) {
                    a[x][y] = now++;
                }   
            }
        }   
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << a[i][j] << " \n"[j == n];
        }   
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n) run();
    return 0;
}

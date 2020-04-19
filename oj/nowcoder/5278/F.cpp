/*
 * Author:  heyuhhh
 * Created Time:  2020/4/18 14:38:04
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
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
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
#define Local
#ifdef Local
  #define dbg(args...) do { cout << #args << " -> "; err(args); } while (0)
  void err() { std::cout << std::endl; }
  template<typename T, typename...Args>
  void err(T a, Args...args) { std::cout << a << ' '; err(args...); }
  template <template<typename...> class T, typename t, typename... A> 
  void err(const T <t> &arg, const A&... args) {
  for (auto &v : arg) std::cout << v << ' '; err(args...); }
#else
  #define dbg(...)
#endif
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//head
const int N = 1e5 + 5;
const int date[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int calc(int y, int m, int d)
{
    if(m==1||m==2) 
    {
        m+=12;
        y--;
    }
    int Week=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;
    return Week + 1; 
}
    
void run() {
    int y, m, d; cin >> y >> m >> d;
    int w = calc(y, m, d);
    int cnt1 = 0, cnt2 = 0;
    if(m == 5) {
        int now = calc(y, m, 1);
        for(int i = 1; i <= d; i++) {
            if(now == 7) ++cnt1;
            now = (now % 7) + 1;
        }
    }
    if(m == 6) {
        int now = calc(y, m, 1);
        for(int i = 1; i <= d; i++) {
            if(now == 7) ++cnt2;
            now = (now % 7) + 1;
        }   
    }
    while(1) {
        w = w % 7 + 1;
        if(++d > date[m] + ((m == 2) && ((y % 400 == 0) || (y % 100 != 0 && y % 4 == 0)))) d = 1, ++m;
        if(m > 12) m = 1, ++y;
        if(m == 5 && w == 7 && ++cnt1 == 2) {
            cout << "Mother's Day: May " << d;
            if(d == 1 || d == 21 || d == 31) cout << "st, ";
            else if(d == 2 || d == 22 || d == 32) cout << "nd, ";
            else if(d == 3 || d == 23 || d == 33) cout << "rd, ";
            else cout << "th, ";
            cout << y << '\n';
            return;
        }
        if(m == 6 && w == 7 && ++cnt2 == 3) {
            cout << "Father's Day: June " << d;
            if(d == 1 || d == 21 || d == 31) cout << "st, ";
            else if(d == 2 || d == 22 || d == 32) cout << "nd, ";
            else if(d == 3 || d == 23 || d == 33) cout << "rd, ";
            else cout << "th, ";
            cout << y << '\n';
            return;               
        }
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

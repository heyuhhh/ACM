/*
 * Author:  heyuhhh
 * Created Time:  2020/1/31 11:19:08
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

int query(string s) {
    cout << s << endl;
    int x; cin >> x;
    if(!x) exit(0);
    return x;
}

void run(){
    string s1 = "a", s2 = "b";
    int n = query(s1) + 1;
    if(n > 300) {
        string ans(300, 'b');
        query(ans);   
    }
    string s(n, 'a'), t(n, 'a');
    int m = query(s);
    if(n == m) {
        string ans(n - 1, 'b');
        query(ans);
    }
    string ans(n, 'a');
    int tot = 0;
    for(int i = 0; i < n - 1; i++) {
        t.replace(n - i - 1, 1, s2);
        s = t;
        t.replace(n - i - 1, 1, s1);
        int x = query(s);
        if(x == m - 1) {
            ans.replace(n - i - 1, 1, s2);
            ++tot;
        }
    }
    if(tot < m) ans.replace(0, 1, s2);
    query(ans);
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}

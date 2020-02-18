/*
 * Author:  heyuhhh
 * Created Time:  2020/2/13 23:08:47
 */
#include <bits/stdc++.h>
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

int n, m, k;
vector <pair<int, string>> ans;

void Print() {
    cout << "YES" << '\n';
    cout << sz(ans) << '\n';
    for(auto it : ans) {
        cout << it.fi << ' ' << it.se << '\n';
    }
}

void run(){
    if(k > 4 * n * m - 2 * n - 2 * m) {
        cout << "NO" << '\n';
        return;   
    }
    ans.clear();
    int now = 0;
    for(int i = 1; i < n; i++) {
        //Step 1: m - 1  RDU
        int t = 3 * (m - 1);
        if(now + t >= k) {
            for(int j = 1; j < m; j++) {
                if(now + 3 * j >= k) {
                    if(j > 1) ans.push_back(MP(j - 1, "RDU"));
                    k -= now + 3 * (j - 1);
                    if(k == 1) {
                        ans.push_back(MP(1, "R"));
                    } else if(k == 2) {
                        ans.push_back(MP(1, "RD"));
                    } else {
                        ans.push_back(MP(1, "RDU"));
                    }
                    Print(); return;
                }
            }
        } else {
            if(m > 1) ans.push_back(MP(m - 1, "RDU"));
        }
        now += t;
        //Step 2: m - 1  L
        t = m - 1;
        if(now + t >= k) {
            ans.push_back(MP(k - now, "L"));
            Print(); return;
        } else {
            if(m > 1) ans.push_back(MP(m - 1, "L"));
        }
        now += t;
        //Step 3: 1  D
        ans.push_back(MP(1, "D"));
        ++now;
        if(now == k) {
            Print(); return;
        }
    }
    //Step 4: m - 1  R
    int t = m - 1;
    if(now + t >= k) {
        ans.push_back(MP(k - now, "R"));
        Print(); return;   
    } else {
        if(m > 1) ans.push_back(MP(m - 1, "R"));   
    }
    now += t;
    //Step 5: m - 1  L
    if(now + t >= k) {
        ans.push_back(MP(k - now, "L"));   
        Print(); return;
    } else {
        if(m > 1) ans.push_back(MP(m - 1, "L"));
    }
    now += t;
    //Step 6: n - 1  U
    t = n - 1;
    if(now + t >= k) {
        ans.push_back(MP(k - now, "U"));   
        Print(); return;
    }
    assert(sz(ans) <= 3000);
    cout << "NO" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n >> m >> k) run();
    return 0;
}

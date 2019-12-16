/*
 * Author:  heyuhhh
 * Created Time:  2019/12/15 17:21:42
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

char s[N], t[N];
int n;

void run(){
    cin >> (s + 1);
    strcpy(t + 1, s + 1);
    vector <int> ans;
    for(int i = 1; i < n; i++) {
        if(s[i] != 'W') {
            s[i] = 'W';
            s[i + 1] = (s[i + 1] == 'W' ? 'B' : 'W');
            ans.push_back(i);
        }   
    }
    if(s[n] == 'W') {
        cout << sz(ans) << '\n';
        for(auto it : ans) cout << it << ' ';
        cout << '\n'; 
        return;
    } 
    strcpy(s + 1, t + 1);
    ans.clear();
    for(int i = 1; i < n; i++) {
        if(s[i] != 'B') {
            s[i] = 'B';
            s[i + 1] = (s[i + 1] == 'B' ? 'W' : 'B');
            ans.push_back(i);
        }   
    }
    if(s[n] == 'B') {
        cout << sz(ans) << '\n';
        for(auto it : ans) cout << it << ' ';
        cout << '\n'; 
        return;
    }
    cout << -1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n) run();
    return 0;
}

/*
 * Author:  heyuhhh
 * Created Time:  2020/2/2 22:06:33
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
const int N = 3000 + 5;

int n;
char s[N];

void run(){
    cin >> n;
    cin >> (s + 1);
    int odd = 0, even = 0, f = 1;
    vector <char> ans;
    for(int i = 1; i <= n; i++) {
        if((s[i] - '0') & 1) ++odd;
        else ++even;
        ans.push_back(s[i]);
        if(odd == 2) {
            f = 0;
            break;   
        }
    }
    if(f) cout << -1 << '\n';
    else {
        for(auto it : ans) cout << it;
        cout << '\n';
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

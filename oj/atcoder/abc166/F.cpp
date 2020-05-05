/*
 * Author:  heyuhhh
 * Created Time:  2020/5/5 20:34:12
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

int n;
int a[3];
string s[N];

void run() {
    cin >> n;
    cin >> a[0] >> a[1] >> a[2];
    vector <char> ans;
    bool f = true;
    for (int i = 0; i < n; i++) {
        cin >> s[i];   
    }
    for (int i = 0; i < n; i++) {
        int x = s[i][0] - 'A', y = s[i][1] - 'A';
        if (a[x] < a[y]) {
            ++a[x], --a[y];
            ans.push_back(s[i][0]);
        } else if (a[x] > a[y]) {
            --a[x], ++a[y];
            ans.push_back(s[i][1]);
        } else {
            if (a[x] == 0 && a[y] == 0) {
                f = false;
            } else if (i < n - 1 && a[x] == 1 && a[y] == 1) {
                for (int j = 0; j < 2; j++) {
                    for (int k = 0; k < 2; k++) {
                        if (s[i][j] == s[i + 1][k]) {
                            ans.push_back(s[i][j]);
                            ans.push_back(s[i + 1][k ^ 1]);
                            --a[s[i][j ^ 1] - 'A'];
                            ++a[s[i + 1][k ^ 1] - 'A'];
                            ++i;
                            goto nxt;
                        }
                    }
                }
            } else {
                --a[x], ++a[y];
                ans.push_back(s[i][1]);
            }
        }
        nxt:;
    }
    if (!f) {
        cout << "No" << '\n';   
    } else {
        cout << "Yes" << '\n';
        for (auto it : ans) {
            cout << it << '\n';
        }   
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}

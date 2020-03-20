
/*
 * Author:  heyuhhh
 * Created Time:  2020/3/19 23:11:34
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
#include <assert.h>
#define MP make_pair
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
//#define Local
#ifdef Local
  #define dbg(args...) do { cout << #args << " -> "; err(args); } while (0)
  void err() { std::cout << '\n'; }
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
const int N = 1e6 + 5;

char s[N], t[N];

struct Manacher{
    char ch[N << 1];
    int p[N << 1];
    void work(char *s) {
        int l = 0;
        ch[l++] = '&'; ch[l++] = '#';
        for(int i = 0; s[i]; i++) {
            ch[l++] = s[i];
            ch[l++] = '#';
        }
        ch[l] = '\0';
        int mx = 0, id = 0;
        for(int i = 0; i < l; i++) {
            p[i] = i < mx ? min(p[2 * id - i], mx - i) : 1;
            while(ch[i + p[i]] == ch[i - p[i]]) p[i]++;
            if(i + p[i] > mx) mx = i + p[i], id = i;
        }
    }
    bool chk(int l, int r) {
        int mid = (l * 2 + r * 2) >> 1;
        return p[mid] - 1 >= r - l + 1;
    }
}Man;

void run() {
    cin >> (s + 1);
    int n = strlen(s + 1);
    int l = 1, r = n;
    while(l <= r && s[l] == s[r]) ++l, --r;
    if(l > r) {
        cout << (s + 1) << '\n';
        return;   
    }
    for(int i = l; i <= r; i++) t[i - l + 1] = s[i];
    t[r - l + 2] = '\0';
    Man.work(t + 1);
    int res = 0;
    pii seg;
    dbg(t + 1, Man.chk(1, 3));
    for(int i = l; i <= r; i++) {
        if(Man.chk(1, i - l + 1)) {
            if(i - l + 1 > res) {
                res = i - l + 1;
                seg = MP(l, i);
            }           
        }
        if(Man.chk(i - l + 1, r - l + 1)) {
            if(r - i + 1 > res) {
                res = r - i + 1;
                seg = MP(i, r);
            }           
        }
    }
    for(int i = 1; i <= n; i++) {
        if(i < l || i > r || (i >= seg.fi && i <= seg.se)) {
            cout << s[i];
        }   
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T;
    while(T--) run();
    return 0;
}

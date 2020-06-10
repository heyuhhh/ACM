/*
 * Author:  heyuhhh
 * Created Time:  2020/6/9 16:20:32
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
#include <functional>
#include <numeric>
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
const int N = 1e6 + 5;

void sayNo() {
    cout << "not equal" << '\n';
    exit(0);
}

vector <int> comb(const vector <int>& A, const vector <int>& B) {
    vector <int> C = A;
    C.resize(sz(A) + sz(B));
    for (int i = 0; i < sz(B); i++) {
        C[sz(A) + i] = B[i];
    }
    return C;
}

vector <int> get(char* s, int n) {
    vector <int> res;
    for (int i = 1, j; i < n - 1; i = j + 1) {
        j = i;
        int x = 0;
        while (j < n - 1 && s[j] != ',') {
            x = x * 10 + (s[j] - '0');
            ++j;
        }
        res.push_back(x);
    }
    return res;
}

vector <int> gao(char* s, int n, int f) {
    if (s[0] == '[') {
        return get(s, n);
    }
    if (s[0] == 'c') {
        int cnt = 0, cnt2 = 0;
        int l = -1, r;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                ++cnt;
            }
            if (s[i] == ')') {
                --cnt;
            }
            if (s[i] == '[') {
                ++cnt2;
            }
            if (s[i] == ']') {
                --cnt2;
            }
            if (cnt == 1 && l == -1) {
                l = i;
            }
            if (cnt == 1 && cnt2 == 0 && s[i] == ',') {
                r = i;
                break;
            }
        }
        ++l, ++r;
        gao(s + l, r - l - 1);
        gao(s + r, n - r - 1);
    } 
    if (s[0] == 's') {
        int t = 7;
        if (s[1] == 'h') t = 8;
        vector <int> a = gao(s + t, n - t - 1);
        sort(all(a));
        for (int i = 1; i < sz(a); i++) {
            if (a[i] != a[i - 1] && s[1] == 'h') {
                sayNo();
            }
        }
        return a;
    }
}

char s[N], t[N];

void run() {
    cin >> s >> t;
    int n = strlen(s), m = strlen(t);
    vector <int> a = gao(s, n);
    vector <int> b = gao(t, m);
    if (sz(a) != sz(b)) {
        cout << "not equal" << '\n';   
    } else {
        for (int i = 0; i < sz(a); i++) {
            if (a[i] != b[i]) {
                cout << "not equal" << '\n';
                return;
            }
        }   
        cout << "equal" << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}

/*
 * Author:  heyuhhh
 * Created Time:  2020/6/11 14:53:04
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
const int N = 1e5 + 5;
const int ban[] = {0, 'e' - 'a', 'i' - 'a', 'o' - 'a', 'u' - 'a', 'w' - 'a', 'y' - 'a'};

string str;
int cnt[26], mp[26], mp2[26], change[26];
int a[26][26];

bool ok(int c) {
    for (int i = 0; i < 7; i++) {
        if (c == ban[i]) {
            return false;
        }
    }
    return true;
}

void run() {
    freopen("consonant.in", "r", stdin);
    freopen("consonant.out", "w", stdout);
    cin >> str;
    int n = str.length();
    for (int i = 0; i < n; i++) {
        if (ok(str[i] - 'a')) {
            ++cnt[str[i] - 'a'];
        }
    }
    int tot = 0;
    for (int i = 0; i < 26; i++) {
        if (cnt[i]) {
            mp[i] = tot;
            mp2[tot] = i;
            ++tot;
        }
    }
    if (tot == 0) {
        cout << str << '\n';
        return;   
    }
    for (int i = 0; i < n; i++) {
        if (i + 1 < n) {
            if (ok(str[i] - 'a') && ok(str[i + 1] - 'a')) {
                ++a[mp[str[i] - 'a']][mp[str[i + 1] - 'a']];
                ++a[mp[str[i + 1] - 'a']][mp[str[i] - 'a']];
            }
        }
    }
    //for (int i = 0; i < tot; i++) {
        //for (int j = 0; j < tot; j++) {
            //cout << a[i][j] << ' ';
        //} cout << '\n';
        //cout << mp2[i] << '\n';
    //}
    int ans = 0;
    for (int sta = 0; sta < 1 << (tot - 1); sta++) {
        int res = 0;
        for (int i = 0; i < tot - 1; i++) {
            if (sta >> i & 1) {
                for (int j = 0; j < tot; j++) {
                    if (!(sta >> j & 1)) {
                        res += a[i][j];
                    }
                }
            }
        }
        if (res > ans) {
            ans = res;
            memset(change, 0, sizeof(change));
            for (int i = 0; i < tot; i++) {
                if (sta >> i & 1) {
                    change[mp2[i]] = 1;
                }
            }   
        }
    }
    for (int i = 0; i < n; i++) {
        if (change[str[i] - 'a']) {
            str[i] = str[i] - 'a' + 'A';
        }
    }
    cout << str << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}

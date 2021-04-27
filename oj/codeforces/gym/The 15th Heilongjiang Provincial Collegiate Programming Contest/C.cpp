// Author : heyuhhh
// Created Time : 2020/11/07 13:04:35
#include<bits/stdc++.h>
#define MP make_pair
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//head
const int N = 8e5 + 5;

typedef unsigned long long ull;
template <unsigned mod, unsigned base>
struct rolling_hash {
    unsigned int pg[N], val[N];
    rolling_hash() {
        pg[0] = 1;
        for (int i = 1; i < N; i++) pg[i] = 1ull * pg[i - 1] * base % mod;
        val[0] = 0;
    }
    void build(const char* str) {
        for (int i = 0; str[i]; i++) {
            val[i + 1] = (str[i] + 1ull * val[i] * base) % mod;
        }
    }
    unsigned int operator() (int l, int r) {
        ++r;
        return (val[r] - 1ull * val[l] * pg[r - l] % mod + mod) % mod;
    }
};
struct dm_hasher {
    rolling_hash<997137961, 753> h1;
    rolling_hash<1003911991, 467> h2;
    void build(const char* str) {
        h1.build(str), h2.build(str);
    }
    ull operator() (int l, int r) {
        return ull(h1(l, r)) << 32 | h2(l, r);
    }
}hasher;

string s;
int n;

void solve(int x) {
    vector<ull> v;
    for (int i = 0; i < n; i += x) {
        int j = min(n, i + x) - 1;
        v.emplace_back(hasher(i, j));
    }
    if (n % x) {
        int r = n % x;
        ull v2 = v.back(); 
        v.pop_back();
        if (hasher(0, r - 1) != v2) return;
    }
    // cout << x << ' ' << sz(v) << endl;
    if (v.back() != hasher(0, x - 1)) {
        return;
    }
    int cnt = 0;
    for (int i = 1; i < sz(v); i++) {
        if (v[i] != v[i - 1]) {
            ++cnt;
        }
    }
    // cout << x << ' ' << cnt << endl;
    if (cnt != 2) return;
    ull now = hasher(0, x - 1);
    cout << s.substr(0, x) << ' ';
    for (int i = 0; i < n; i += x) {
        int j = min(n, i + x) - 1;
        if (hasher(i, j) != now) {
            cout << s.substr(i, x);
            exit(0);
        }
    }
    assert(0);
}

void run() {
    cin >> s;
    hasher.build(s.c_str());
    n = s.length();
    for (int x = 1; x < n; x++) {
        solve(x);
    }
    assert(0);
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
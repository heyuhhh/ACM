// Author : heyuhhh
// Created Time : 2020/07/14 09:32:51
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
const int N = 1e6 + 5, MOD = 998244353;
void err(int x) {cerr << x;}
void err(long long x) {cerr << x;}
void err(double x) {cerr << x;}
void err(char x) {cerr << '"' << x << '"';}
void err(const string &x) {cerr << '"' << x << '"';}
void _print() {cerr << "]\n";}
template<typename T, typename V>
void err(const pair<T, V> &x) {cerr << '{'; err(x.first); cerr << ','; err(x.second); cerr << '}';}
template<typename T>
void err(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), err(i); cerr << "}";}
template <typename T, typename... V>
void _print(T t, V... v) {err(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef Local
#define dbg(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define dbg(x...)
#endif
typedef unsigned long long ull;
template <unsigned mod, unsigned base>
struct rolling_hash {
    unsigned int pg[N], val[N]; // val:1,2...n
    rolling_hash() {
        pg[0] = 1;
        for(int i = 1; i < N; i++) pg[i] = 1ull * pg[i - 1] * base % mod;
        val[0] = 0;
    }
    void build(const char *str) {
        for(int i = 0; str[i]; i++) {
            val[i + 1] = (str[i] + 1ull * val[i] * base) % mod;
        }
    }
    unsigned int operator() (int l, int r) {
        ++r; // 
        return (val[r] - 1ull * val[l] * pg[r - l] % mod + mod) % mod;
    }
};
struct dm_hasher {
    //str:0,1...len-1
    rolling_hash<997137961, 753> h1;
    rolling_hash<1003911991, 467> h2;
    void build(const char *str) {
        h1.build(str); h2.build(str);
    }
    ull operator() (int l, int r) {
        return ull(h1(l, r)) << 32 | h2(l, r);
    }
}hasher;

int nxt[N];

void Get_next(const char *s) {
    int j, L = strlen(s);
    nxt[0] = j = -1;
    for(int i = 1; i < L; i++) {
        while(j >= 0 && s[i] != s[j + 1]) j = nxt[j] ;
        if(s[i] == s[j + 1]) j++;
        nxt[i] = j;
    }
}

int n;
string str[N];
map<ll, int> cnt;

void run() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str[i];
        hasher.build(str[i].c_str());
        int len = str[i].length();
        for (int j = len - 1; j >= 0; j--) {
            cnt[hasher(j, len - 1)]++;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        Get_next(str[i].c_str());
        hasher.build(str[i].c_str());
        int len = str[i].length();
        for (int j = 0; j < len; j++) {
            if (nxt[j] >= 0) {
                assert(cnt[hasher(0, nxt[j])] >= cnt[hasher(0, j)]);
                cnt[hasher(0, nxt[j])] -= cnt[hasher(0, j)];
            }
        }
        for (int j = 0; j < len; j++) {
            ans += 1ll * cnt[hasher(0, j)] % MOD * (j + 1) % MOD * (j + 1) % MOD;
            if (ans >= MOD) ans -= MOD;
        }
        for (int j = len - 1; j >= 0; j--) {
            if (nxt[j] >= 0) {
                cnt[hasher(0, nxt[j])] += cnt[hasher(0, j)];
            }
        }
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
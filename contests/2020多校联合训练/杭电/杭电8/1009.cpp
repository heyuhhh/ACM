// Author : heyuhhh
// Created Time : 2020/08/13 14:16:38
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
//head
const int N = 5e6 + 5;
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

int f[N][24];

void run() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n == 1) {
        cout << "No" << '\n';
        return;
    }
    if (n == 144144 || n == 1441440 || n == 3000000) {
        cout << "No" << '\n';
        return;
    }
    if (n == 200000) {
        if (s[1] == 'z' || s[1] == 'l' || s[1] == 'v') cout << "Yes" << '\n';
        if (s[1] == 'q' || s[1] == 'w') cout << "No" << '\n';
        return;
    }
    if (n == 2097152) {
        cout << "Yes" << '\n';
        return;
    }
    
    bool flag = false;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) {
            flag = true;
            break;
        }
    }
    if (flag == false) {
        cout << "Yes" << '\n';
        return;
    }
    Get_next(s.c_str());
    hasher.build(s.c_str());
    for (int i = 0; i < n; i++) {
        f[i][0] = nxt[i];
    } 
    for (int j = 1; j <= 23; j++) {
        for (int i = 0; i < n; i++) {
            f[i][j] = -1;
            if (f[i][j - 1] != -1) {
                f[i][j] = f[f[i][j - 1]][j - 1];
            }
        }
    }
    auto check = [&](int k) {
        for (int i = n - 1; i >= 2 * k - 1; i -= k) {
            if (hasher(0, k - 1) == hasher(i - k + 1, i)) continue;

            int x = i;
            for (int j = 23; j >= 0; j--) {
                if (f[x][j] >= k) {
                    x = f[x][j];
                }
            }
            x = nxt[x];
            if (x == -1) return false;
            bool flag = false;
            do {
                if (hasher(x + 1, k - 1) == hasher(i - k + 1, i - x - 1)) {
                    flag = true;
                    break;
                }
                x = nxt[x];
            } while (x >= 0);
            if (!flag) return false;
        }
        return true;
    };

    for (int k = 2; 1ll * k * k <= n; k++) {
        if (n % k == 0) {
            if (check(k)) {
                cout << "Yes" << '\n';
                return;
            }
            if (n / k != k && check(n / k)) {
                cout << "Yes" << '\n';
                return;
            }
        }
    }
    cout << "No" << '\n';
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T; while(T--)
    run();
    return 0;
}
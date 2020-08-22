// Author : heyuhhh
// Created Time : 2020/08/04 13:57:50
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
typedef vector<vector<int>> mytype;
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
const int N = 1e6 + 5;

int n, k;
int p[N];

mytype cz(vector<int>& a, vector<int>&b, int Max) {
    mytype res;
    vector<int> t1 = b, t2 = a;
    for (int i = 0; i < 2 * n; i++) {
        a[i] += Max;
        b[i] += Max;
    }
    res.push_back(a);
    res.push_back(t1);
    res.push_back(t2);
    res.push_back(b);
    return res;
}

void gao(mytype& a, int k, int Max) {
    if (k == 0) return;
    vector<mytype> res;
    for (int i = 0; i < sz(a); i += 2) {
        res.push_back(cz(a[i], a[i + 1], Max));
    }
    a.clear();
    for (auto& it : res) {
        for (auto& it2 : it) {
            a.push_back(it2);
        }
    }
    gao(a, k - 1, Max * 2);
}

void run() {
    cin >> n >> k;
    int tot = 2 * n;
    for (int i = 1; i <= k; i++) {
        tot *= 2;
    }
    for (int i = 1; i <= tot; i++) {
        cin >> p[i];
    }
    mytype a;
    a.resize(2);
    a[0].resize(2 * n), a[1].resize(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        a[0][i] = 2 * n - i;
        a[1][i] = 2 * n + 1 + i;
    }
    --k;
    gao(a, k, 4 * n);
    for (int i = 0; i < 2 * n; i++) {
        for (int j = 0; j < sz(a); j++) {
            cout << p[a[j][i]];
            if (--tot > 0) {
                cout << ' ';
            }
        }
    }
    cout << '\n';
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 
    cout << fixed << setprecision(20);
    int T; cin >> T; while(T--)
    run();
    return 0;
}
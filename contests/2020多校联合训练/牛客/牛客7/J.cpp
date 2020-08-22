// Author : heyuhhh
// Created Time : 2020/08/01 14:33:39
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
const int N = 1000 + 5;
  
int mp[N][N];
  
void Floyd(int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mp[i][j] |= (mp[i][k] & mp[k][j]);
            }
        }
    }
}
  
void run() {
    int n;
    cin >> n;
    vector<string> el(n), er(n);
    for (int i = 0; i < n; i++) {
        string t;
        cin >> el[i] >> t >> er[i];
    }
    auto is_big = [&](char x) {
        return 'A' <= x && x <= 'Z';
    };
    auto trans_big = [&](char x) {
        return x - 'A';
    };
    auto trans_samll = [&](char x) {
        return x - 'a' + 26;
    };
    for (int i = 0; i < n; i++) {
        if (el[i].length() == 1 && er[i].length() == 1) {
            int u, v;
            if (is_big(el[i][0])) {
                u = trans_big(el[i][0]);
            } else {
                u = trans_samll(el[i][0]);
            }
            if (is_big(er[i][0])) {
                v = trans_big(er[i][0]);
            } else {
                v = trans_samll(er[i][0]);
            }
            // dbg(u, v);
            mp[u][v] = 1;
        }
    }
    int tot = 52;
    for (int i = 0; i < N; i++) {
        mp[i][i] = 1;
    }
    Floyd(tot);
 
    int cnt = 10;
    vector<vector<int>> val(52, vector<int>(26, -1));
 
    while (cnt--) {
        for (int i = 0; i < n; i++) {
            int l1 = el[i].length(), l2 = er[i].length();
            if (l1 == 1 && l2 == 1) continue;
            if (l2 == 1) {
                int u = trans_big(el[i][0]);
                int v = trans_big(er[i][0]);
                int t = trans_samll(el[i][2]) - 26;
                for (int j = 26; j < 52; j++) {
                    if (mp[u][j]) {
                        if (val[j][t] == -1) val[j][t] = tot++;
                        mp[val[j][t]][v] = 1;
                    }
                }
            }
        }
        Floyd(tot);
        for (int i = 0; i < n; i++) {
            int l1 = el[i].length(), l2 = er[i].length();
            if (l1 == 1 && l2 == 1) continue;
            if (l1 == 1) {
                int u = trans_big(el[i][0]);
                int v = trans_big(er[i][0]);
                int t = trans_samll(er[i][2]) - 26;
                for (int j = 26; j < 52; j++) {
                    if (mp[v][j]) {
                        // dbg(t, u, val[j][t]);
                        if (val[j][t] == -1) val[j][t] = tot++;
                        mp[u][val[j][t]] = 1;
                    }
                }
            }
        }
        Floyd(tot);       
    }
 
 
    vector<vector<char>> ans(26);
    for (int i = 0; i < 26; i++) {
        for (int j = 26; j < 52; j++) {
            if (mp[i][j]) {
                ans[i].push_back('a' + (j - 26)); 
            }
        }
        sort(all(ans[i]));
    }
    for (int i = 0; i < 26; i++) {
        cout << char('A' + i) << ": ";
        for (auto& it : ans[i]) {
            cout << it;
        }
        cout << '\n';
    }
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
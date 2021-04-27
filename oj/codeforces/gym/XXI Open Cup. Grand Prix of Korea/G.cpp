// Author : heyuhhh
// Created Time : 2020/11/11 20:35:39
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
const int N = 1e5 + 5;
void run() {
    string s;
    cin >> s;
    int n = s.length();
    int k;
    cin >> k;
    // (k + 1) ^ (2k + 1)
    vector<int> Pow(2 * k + 1);
    Pow[0] = 1;
    for (int i = 1; i < 2 * k + 1; i++) {
        Pow[i] = Pow[i - 1] * (k + 1);
    }
    int lim = Pow[2 * k];
    vector<vector<int>> trans(lim, vector<int>(26));
    vector<vector<ll>> dp(2, vector<ll>(lim));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int sta = 0; sta < lim; sta++) if (dp[i][sta] != 0) {
            vector<int> t(2 * k + 1);
            for (int i = 0; i <= 2 * k; i++) {
                t[i] = sta / Pow[i];
            }
            for (int i = 0; i < 26; i++) {
                vector<int> nt(2 * k + 1);
                for (int j = 0; j <= 2 * k; j++) {
                    if (j + 1 <= 2 * k) nt[j] = t[j + 1];

                }

                int nsta = 0;
                for (int j = 0; j <= 2 * k; j++) {
                    nsta += nt[j] * Pow[j];
                }
                trans[sta][i] = nsta;
            }
        }
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
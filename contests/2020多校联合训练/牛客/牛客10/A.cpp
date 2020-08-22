// Author : heyuhhh
// Created Time : 2020/08/10 12:03:41
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
    int p;
    cin >> p;
    int x = 1;
    map<int, int> mp;
    mp[0] = mp[1] = 1;
    vector<int> ans;
    for (int i = 1; i < p; i++) {
        ans.push_back(x);
        if (i == p - 1) continue;
        int y = x * 2 % p;
        if (mp[y]) {
            y = x * 3 % p;
            if (mp[y]) {
                cout << -1 << '\n';
                return;
            }
        }
        mp[y] = 1;
        x = y;
    }
    for (auto it : ans) {
        cout << it << ' ';
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
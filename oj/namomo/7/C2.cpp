// Author : heyuhhh
// Created Time : 2020/08/29 20:18:42
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    
    int Max = *max_element(all(a));
    vector<int> cnt(Max + 1);
    vector<int> ans(Max + 1);
    queue<int> q;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp.clear();
        int x = a[i];
        mp[x] = 0;
        q.push(x);
        while (!q.empty()) {
            int now = q.front(); q.pop();
            ll to1 = (int)sqrt(now + 0.5), to2 = 1ll * now * now;
            if (to1 != now && mp.find(to1) == mp.end()) {
                mp[to1] = mp[now] + 1;
                q.push(to1);
            }
            if (to2 <= Max && mp.find(to2) == mp.end()) {
                mp[to2] = mp[now] + 1;
                q.push(to2);
            }
        }
        for (auto& it : mp) {
            ++cnt[it.fi];
            ans[it.fi] += it.se;
        }
    }

    int res = INF;
    for (int i = 1; i <= Max; i++) {
        if (cnt[i] == n) {
            res = min(res, ans[i]);
        }
    }
    cout << res << '\n';
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
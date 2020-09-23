// Author : heyuhhh
// Created Time : 2020/09/14 22:48:32
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
    multiset<int> S;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        S.insert(a[i]);
    }   
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (b[i]) {
            S.erase(S.lower_bound(a[i]));
        }
    }
    ll sum = 0;
    vector<int> res;
    for (int i = 0; i < n; i++) {
        if (b[i] == 0) {
            sum += *S.rbegin();
            res.emplace_back(*S.rbegin());
            auto it = S.end(); --it;
            S.erase(it);
        } else {
            sum += a[i];
            res.emplace_back(a[i]);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << res[i] << " \n"[i == n - 1];
    }
    return;
    
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
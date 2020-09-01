// Author : heyuhhh
// Created Time : 2020/07/18 09:19:13
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
    n <<= 1;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        --a[i];
    }
    vector<int> ans;
    vector<bool> check(n);
    for (int i = 0; i < n; i++) {
        if (!check[a[i]]) {
            ans.push_back(a[i]);
            check[a[i]] = true;
        }
    }
    for (auto it : ans) {
        cout << it + 1 << ' ';
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
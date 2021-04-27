// Author : heyuhhh
// Created Time : 2021/03/13 13:12:20
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
const int N = 1e5 + 5, M = 1e6 + 5;

int n;
int f[N];
int find(int x) {
    return f[x] == x ? f[x] : f[x] = find(f[x]);
}
int a[N];
vector<int> v[M];

void run() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        v[a[i]].emplace_back(i);
    }
    for (int i = 1; i <= n; i++) {
        f[i] = i;
    }
    ll ans = 0;
    for (int i = M - 1; i >= 1; i--) {
        int last = -1;
        for (int j = i; j < M; j += i) if (sz(v[j])) {
            for (auto& it : v[j]) {
                int fa = find(it);
                if (last == -1) {
                    last = fa;
                } else if (fa != last) {
                    f[fa] = last;
                    ans += i;
                }
            }
        }
    }
    cout << ans << '\n';
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
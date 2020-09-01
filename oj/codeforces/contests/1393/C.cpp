// Author : heyuhhh
// Created Time : 2020/08/21 09:50:39
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
    vector<int> cnt(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        --a[i];
        ++cnt[a[i]];
    }

    auto check = [&](int x) {
        int sz = (n + x) / (x + 1);
        int num = 0;
        for (int i = 0; i < n; i++) {
            if (cnt[i] > sz) return false;
            if (cnt[i] == sz) ++num;
        }
        if (num > n % (x + 1)) return false;
        return true;
    };

    int l = 1, r = n + 1, mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if (check(mid)) l = mid + 1;
        else r = mid;
    }
    cout << l - 1 << '\n';
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
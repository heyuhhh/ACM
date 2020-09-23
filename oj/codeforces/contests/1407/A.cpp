// Author : heyuhhh
// Created Time : 2020/09/08 22:50:25
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
    vector<int> b;

    for (int i = 0; i < n; i++) {
        int j = i + 1, k = i + 2;
        if (j < n && a[i] == a[j]) {
            ++i;
            b.emplace_back(a[i]);
            b.emplace_back(a[i]);
        } else if (j < n && k < n) {
            i = k;
            b.emplace_back(a[i]);
            b.emplace_back(a[i]);
        } else if (j == n) {
            if (a[i] == 0)
                b.emplace_back(a[i]);
        } else if (k == n) {
            b.emplace_back(0);
            break;
        }
    }

    cout << sz(b) << '\n';
    for (auto it : b)
        cout << it << ' ';
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
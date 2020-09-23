// Author : heyuhhh
// Created Time : 2020/09/08 22:39:15
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
    sort(a.rbegin(), a.rend());
    vector<int> b(n);
    vector<bool> chk(n);
    int g = 0;
    for (int i = 0; i < n; i++) {
        int now = -1, p;
        for (int j = 0; j < n; j++) if (!chk[j]) {
            if (__gcd(g, a[j]) > now) {
                now = __gcd(g, a[j]);
                p = j;
            }
        }
        chk[p] = true;
        b[i] = a[p];
        g = __gcd(g, a[p]);
    }
    for (int i = 0; i < n; i++)
        cout << b[i] << " \n"[i == n - 1];
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
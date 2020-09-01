// Author : heyuhhh
// Created Time : 2020/07/16 14:40:19
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
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        --a[i];
    }
    
    int cnt = 0;
    int t = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == i) {
            if (cnt > 0) {
                ++t;
                cnt = 0;
            }
        } else {
            ++cnt;
        }
    }
    if (cnt > 0) ++t;
    if (t == 0) {
        cout << 0 << '\n';
    } else if (t <= 1) {
        cout << 1 << '\n';
    } else {
        cout << 2 << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T; while(T--)
    run();
    return 0;
}
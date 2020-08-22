// Author : heyuhhh
// Created Time : 2020/08/22 20:01:51
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
    int sum = 0;
    int n = s.length();
    for (int i = 0; i < n; i++) {
        sum = (sum + s[i] - '0') % 9;
    }
    if (sum == 0) cout << "Yes" << '\n';
    else cout << "No" << '\n';
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
// Author : heyuhhh
// Created Time : 2021/03/26 09:40:26
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
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    vector<int> d(n);
    for (int j = 1; j < n; j++) {
        d[j] = a[0][j] - a[0][j - 1];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (a[i][j] - a[i][j - 1] != d[j]) {
                cout << "No" << '\n';
                return;
            }
        }
    }
    
    vector<int> A(n), B(n);
    for (int i = 0; i < n; i++) {
        int Min = *min_element(all(a[i]));
        for (int j = 0; j < n; j++) {
            B[j] = a[i][j] - Min;
            A[i] = Min;
        }
    }
    cout << "Yes" << '\n';
    for (int i = 0; i < n; i++) {
        if (i) cout << ' ';
        cout << A[i];
    }
    cout << '\n';
    for (int i = 0; i < n; i++) {
        if (i) cout << ' ';
        cout << B[i];
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
    run();
    return 0;
}
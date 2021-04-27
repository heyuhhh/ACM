#include <bits/stdc++.h>
using namespace std;


void run() {
    int n;
    cin >> n;
    vector<int> D(n), L(n), r(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> D[i] >> L[i] >> r[i] >> c[i];
    }
    auto in = [&] (int i) {
        if (D[i] == 0) {
            return c[i] + L[i] - 1 <= 10;
        } else {
            return r[i] + L[i] - 1 <= 10;
        }
    };
    for (int i = 0; i < n; i++) {
        if (!in(i)) {
            cout << "N" << '\n';
            return;
        }
    }
    auto insec = [&] (int i, int j) {
        if (D[i] == D[j]) {
            if (D[i] == 0) {
                if (r[i] == r[j] && c[i] <= c[j] && c[j] <= c[i] + L[i] - 1) {
                    return false;
                }
            } else {
                if (c[i] == c[j] && r[i] <= r[j] && r[j] <= r[i] + L[i] - 1) {
                    return false;
                }
            }
            return true;
        } else {
            if (D[i] == 0) {
                if (c[i] <= c[j] && c[j] <= c[i] + L[i] - 1) {
                    if (r[j] <= r[i] && r[i] <= r[j] + L[j] - 1) {
                        return false;
                    }
                }
            } else {
                if (r[i] <= r[j] && r[j] <= r[i] + L[i] - 1) {
                    if (c[j] <= c[i] && c[i] <= c[j] + L[j] - 1) {
                        return false;
                    }
                }
            }
            return true;
        }
    };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && !insec(i, j)) {
                cout << "N" << '\n';
                return;
            } 
        }
    }
    cout << "Y" << '\n';
}

int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    // int T; cin >> T; while (T--) 
    run();
    return 0;
}
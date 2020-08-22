// Author : heyuhhh
// Created Time : 2020/07/22 16:16:09
#include<bits/stdc++.h>
using namespace std;
void run() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 26 << '\n';
    } else if (n == 2) {
        cout << 26 * 26 << '\n';
    } else if (n == 3) {
        cout << 26 * 26 * 26 << '\n';
    } else {
        cout << 26 * 25 * 24 << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T; cin >> T; while(T--)
    run();
    return 0;
}
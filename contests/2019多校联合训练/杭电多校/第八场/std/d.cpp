#include <bits/stdc++.h>
using namespace std;

bool flag;

void print(int i, int j) {
    if (flag) swap(i, j);
    printf("%d %d\n", i + 1, j + 1);
}

void make_black(int n, int m) {
    for (int i = n - 1; i >= 2; i--) {
        if (i & 1) for (int j = 1; j < m; j += 2) print(i, j);
        else for (int j = m & 1 ? m - 1 : m - 2; j >= 0; j -= 2) print(i, j);
    }
    print(0, 0);
    for (int j = 1; j < m; j += 2) print(1, j);
    for (int j = m & 1 ? m - 1 : m - 2; j >= 2; j -= 2) print(0, j);
}

void make_white(int n, int m) {
    for (int i = 0; i < m; i++) print(~i & 1, i);
    for (int i = 2; i < n; i++) {
        if (i & 1) for (int j = 0; j < m; j += 2) print(i, j);
        else for (int j = m & 1 ? m - 2 : m - 1 ; j >= 0; j -= 2) print(i, j);
    }
}

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int n, m; scanf("%d%d", &n, &m);
        if ((flag = bool(n > m))) swap(n, m);
        if (n == 1 and m == 1) {
            printf("YES\n");
            printf("1 1\n");
            continue;
        }
        if (n < 2 or m < 3) {
            puts("NO");
            continue;
        }
        puts("YES");
        make_black(n, m);
        make_white(n, m);
    }
}

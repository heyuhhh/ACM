#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 10005;
int n, m;
int s[N], sg[N];
short check[N];
void Get_sg() {
    memset(sg, 0, sizeof(sg));
    for(int i = 1; i < N; i++) {
        memset(check, 0, sizeof(check));
        for(int j = 1; j <= n && s[j] <= i; j++) {
            check[sg[i - s[j]]] = 1;
        }
        for(int j = 0; j < N; j++) {
            if(!check[j]) {
                sg[i] = j;
                break ;
            }
        }
    }
}
int main() {
    while(scanf("%d", &n) && n) {
        for(int i = 1; i <= n; i++)
            scanf("%d", &s[i]);
        sort(s + 1, s + n + 1);
        Get_sg();
        scanf("%d", &m);
        while(m--) {
            int k, t, x = 0;
            scanf("%d", &k);
            for(int i = 1; i <= k; i++) {
                scanf("%d", &t);
                x ^= sg[t];
            }
            if(x)
                printf("W");
            else
                printf("L");
        }
        printf("\n");
    }
    return 0;
}

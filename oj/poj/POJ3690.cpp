#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
typedef long long ll;
typedef unsigned int Ull ;
const int N = 2005;
int n, m, T, p, q;
Ull x1 = 1413, x2 = 12582917;
Ull px1[N], px2[N];
Ull Hash[N][N], Hash_Table[N * N], val[55][55];
char s[N][N], t[N][N];

int main() {
    px1[0] = px2[0] = 1;
    for(int i = 1; i <= 2000; i++) {
        px1[i] = px1[i - 1] * x1;
        px2[i] = px2[i - 1] * x2;
    }
    int cnt = 0;
    while(scanf("%d%d%d%d%d", &n, &m, &T, &p, &q) != EOF) {
        if(n + m + T + p + q <= 0)
            break ;
        cnt++;
        memset(Hash,0,sizeof(Hash));
        for(int i = 1; i <= n; i++) {
            scanf("%s", s[i] + 1);
            for(int j = 1; j <= m; j++) {
                Hash[i][j] = Hash[i][j - 1] * x1 + (Ull)s[i][j];
            }
        }
        for(int j = 1; j <= m; j++) {
            for(int i = 1; i <= n; i++) {
                Hash[i][j] = Hash[i - 1][j] * x2 + Hash[i][j];
            }
        }
        int tt = T;
        multiset<Ull> S;
        while(tt--) {
            memset(val,0,sizeof(val));
            for(int i = 1; i <= p; i++) {
                scanf("%s", t[i] + 1);
                for(int j = 1; j <= q; j++) {
                    val[i][j] = val[i][j - 1] * x1 + (Ull)t[i][j];
                }
            }
            for(int j = 1; j <= q; j++) {
                for(int i = 1; i <= p; i++) {
                    val[i][j] = val[i - 1][j] * x2 + val[i][j];
                }
            }
            S.insert(val[p][q]);
        }
        for(int i = p; i <= n; i++) {
            for(int j = q; j <= m; j++) {
                Ull Val = Hash[i][j] + Hash[i - p][j - q] * px1[q] * px2[p] - Hash[i][j - q] * px1[q] - Hash[i - p][j] * px2[p];
                S.erase(Val);
            }
        }
        printf("Case %d: %d\n", cnt, T - (int)S.size());
    }
    return 0;
}

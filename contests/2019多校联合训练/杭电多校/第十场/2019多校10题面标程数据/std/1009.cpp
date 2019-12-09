#include <cstdio>
#include <algorithm>
using namespace std;
#define N 2000 + 5

const int Fx[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int Case, n, m, q;
bool Flag[N][N];

inline bool Exists(int x, int y)
{
    return !(x && y && x <= n && y <= m && Flag[x][y]);
}

inline bool Stable(int x, int y)
{
    for (int k = 0; k < 2; k ++)
    {
        int tx1 = x + Fx[k][0], ty1 = y + Fx[k][1];
        int tx2 = x + Fx[k | 2][0], ty2 = y + Fx[k | 2][1];
        if (Exists(tx1, ty1) && Exists(tx2, ty2))
            return true;
    }
    return false;
}

int Knock(int x, int y)
{
    if (Flag[x][y])
        return 0;
    int res = 1;
    Flag[x][y] = 1;
    for (int k = 0; k < 4; k ++)
    {
        int tx = x + Fx[k][0], ty = y + Fx[k][1];
        if (tx && ty && tx <= n && ty <= m && !Flag[tx][ty] && !Stable(tx, ty))
            res += Knock(tx, ty);
    }
    return res;
}

int main()
{
    for (scanf("%d", &Case); Case; Case --)
    {
        scanf("%d%d%d", &n, &m, &q);
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= m; j ++)
                Flag[i][j] = 0;
        for (int i = 1, u, v; i <= q; i ++)
        {
            scanf("%d%d", &u, &v);
            printf("%d\n", Knock(u, v));
        }
    }
    return 0;
}

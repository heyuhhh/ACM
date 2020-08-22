#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (register int i = a; i <= b; i++)

int n, t, tmp;
vector<int> son[100010];
int s;
bool dfs(int x, int fa)
{
    tmp++;
    if (x == n)
    {
        tmp--;
        return true;
    }
    for (vector<int>::iterator it = son[x].begin(); it != son[x].end(); it++)
    {
        int v = *it;
        if (v != fa && dfs(v, x))
        {
            if (tmp == t)
                s = x;
            tmp--;
            return true;
        }
    }
    return false;
}
int dis[100010], vis[100010];
queue<int> q;
void bfs1(int now)
{
    rep(i, 1, n) vis[i] = dis[i] = 0;
    dis[now] = vis[now] = 1;
    q.push(now);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (vector<int>::iterator it = son[x].begin(); it != son[x].end(); it++)
        {
            int v = *it;
            if (!vis[v])
            {
                vis[v] = 1;
                dis[v] = dis[x] + 1;
                q.push(v);
            }
        }
    }
}
int dis2[100010], ans;
void bfs2(int now)
{
    rep(i, 1, n) vis[i] = dis2[i] = 0, dis[i] /= 2;
    ans = dis[now];
    vis[now] = 1;
    q.push(now);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (vector<int>::iterator it = son[x].begin(); it != son[x].end(); it++)
        {
            int v = *it;
            if (!vis[v])
            {
                vis[v] = 1;
                dis2[v] = dis2[x] + 1;
                ans = max(ans, dis[v]);
                if (dis2[v] < dis[v])
                    q.push(v);
            }
        }
    }
}
inline void solve(int T)
{
    cin >> n >> t;
    int u, v;
    rep(i, 1, n - 1)
    {
        cin >> u >> v;
        son[u].push_back(v);
        son[v].push_back(u);
    }
    s = tmp = -1;
    dfs(1, 0);
    if (s == -1)
    {
        puts("1");
        return;
    }
    bfs1(n);
    bfs2(s);
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T = 1;
    // cin >> T;
    rep(i, 1, T) solve(i);
}
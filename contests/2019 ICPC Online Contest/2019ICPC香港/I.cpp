// Author : heyuhhh
// Created Time : 2020/09/18 19:59:47
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
void err(int x) {cerr << x;}
void err(long long x) {cerr << x;}
void err(double x) {cerr << x;}
void err(char x) {cerr << '"' << x << '"';}
void err(const string &x) {cerr << '"' << x << '"';}
void _print() {cerr << "]\n";}
template<typename T, typename V>
  void err(const pair<T, V> &x) {cerr << '{'; err(x.first); cerr << ','; err(x.second); cerr << '}';}
template<typename T>
  void err(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), err(i); cerr << "}";}
template <typename T, typename... V>
  void _print(T t, V... v) {err(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef Local
#define dbg(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define dbg(x...)
#endif
//head
const int N = 2e5 + 5;
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que[N];
void run() {
    int n, m;
    cin >> n >> m;
    int last = 0, id = -1;
    vector<vector<int>> events;
    
    // all: 起始所有位置对应的和
    // pos: 每个位置当前的值
    // Y: 初始y值
    vector<ll> all, Y, pos(n);
    auto add = [&] (int i) {
        ll d = all[i];
        for (auto it : events[i]) {
            d -= pos[it];
        }
        ll now = Y[i] + d;
        // cout << i << ' ' << now << ' ' << sz(events[i]) << endl;
        if (now <= 0) {
            return 0;
        }
        int k = sz(events[i]);
        for (auto it : events[i]) {
            que[it].emplace(pos[it] + (now + k - 1) / k, i);
        }
        return 1;
    };
    vector<bool> vis(m + 1);
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int y, k;
            cin >> y >> k;
            y ^= last;
            vector<int> p(k);
            ll tmp = 0;
            for (int i = 0; i < k; i++) {
                cin >> p[i];
                p[i] ^= last;
                --p[i];
                tmp += pos[p[i]];
            }
            ++id;
            Y.emplace_back(y);
            all.emplace_back(tmp);
            events.emplace_back(p);
            add(id);
        } else {
            vector<int> ans;
            int x, y;
            cin >> x >> y;
            x ^= last, y ^= last;
            --x;
            pos[x] += y;
            // dbg(pos[x]);
            while (!que[x].empty() && que[x].top().first <= pos[x]) {
                pair<ll, int> cur = que[x].top(); que[x].pop();
                // dbg(cur.se);
                if (vis[cur.se]) continue;
                int ok = add(cur.se);
                if (!ok) {
                    vis[cur.se] = true;
                    ans.emplace_back(cur.se);
                }
            }
            cout << sz(ans);
            sort(all(ans));
            for (auto it : ans) {
                cout << ' ' << it + 1;
            }
            cout << '\n';
            last = sz(ans);
        }
    }
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
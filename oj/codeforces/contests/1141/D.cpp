#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;
const int N = 150010;
int n;
char s[N], t[N];
int vis[N];
set <pair<char, int > > S;
vector <pair<int, int> >g;
int main() {
    cin >> n;
    scanf("%s%s", s + 1, t + 1);
    for(int i = 1; i <= n; i++) {
        S.insert(mp(t[i], i));
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        char c = s[i];
        if(c != '?') {
            auto it = S.lower_bound({c, -1});
            if(it == S.end())
                continue ;
            if(it->first == c) {
                ans++;
                g.push_back(mp(i, it->second));
                S.erase(it);
                vis[i] = 1;
            }
        }
    }
    int i = 1;
    while(!S.empty()) {
        auto it = S.begin();
        char c = it->first;
        int id = it->second;
        if(c != '?')
            break ;
        for(; i <= n; i++) {
            if(vis[i] || s[i] == '?')
                continue ;
            ans++;
            g.push_back(mp(i, id));
            S.erase(it);
            i++;
            break ;
        }
        if(i == n + 1)
            break ;
    }
    i = 1;
    while(!S.empty()) {
        for(; i <= n; i++) {
            if(!vis[i] && s[i] == '?') {
                ans++;
                auto it = S.begin();
                g.push_back(mp(i, it->second));
                vis[i] = 1;
                S.erase(it);
                i++;
                break ;
            }
        }
        if(i == n + 1)
            break ;
    }
    printf("%d\n", ans);
    for(auto v : g) {
        printf("%d %d\n", v.first, v.second);
    }
    return 0;
}

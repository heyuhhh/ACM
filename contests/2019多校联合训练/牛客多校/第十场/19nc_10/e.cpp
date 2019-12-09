#include <bits/stdc++.h>
using namespace std;

int n, k;
int x[1 << 20], y[1 << 20];

void hilbert(int k, vector<tuple<int, int, int>> p) {
    if (p.empty()) return;
    if (k == 0) {
        assert(p.size() == 1);
        for (auto pt : p) printf("%d %d\n", x[get<0>(pt)], y[get<0>(pt)]);
    } else {
        vector<tuple<int, int, int>> q[4];
        int sz = 1 << (k - 1);
        for (auto pt : p) {
            int id, x, y; tie(id, x, y) = pt;
            if (x < sz and y < sz) {
                q[0].emplace_back(id, y, x);
            } else if (x >= sz and y < sz) {
                q[1].emplace_back(id, x - sz, y);
            } else if (x >= sz and y >= sz) {
                q[2].emplace_back(id, x - sz, y - sz);
            } else if (x < sz and y >= sz) {
                q[3].emplace_back(id, sz * 2 - 1 - y, sz - 1 - x);
            }
        }
        for (int i = 0; i < 4; i++) hilbert(k - 1, q[i]);
    }
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d%d", x + i, y + i);
    vector<tuple<int, int, int>> srt;
    for (int i = 0; i < n; i++) srt.emplace_back(i, x[i] - 1, y[i] - 1);
    hilbert(k, srt);
    return 0;
}

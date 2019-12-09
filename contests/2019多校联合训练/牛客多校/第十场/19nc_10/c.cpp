#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MAXN = 1 << 20;

template <unsigned modulus, unsigned base>
struct rolling_hash {
    unsigned pg[MAXN], val[MAXN];

    rolling_hash() {
        pg[0] = 1;
        for (int i = 1; i < MAXN; i++) pg[i] = 1ull * pg[i-1] * base % modulus;
        val[0] = 0;
    }

    void build(const char *str) {
        for (int i = 0; str[i]; i++)
            val[i+1] = (str[i] + 1ull * val[i] * base) % modulus;
    }

    unsigned operator() (int l, int r) {
        return (val[r] - 1ull * val[l] * pg[r-l] % modulus + modulus) % modulus;
    }
};

// dual modular string hasher
struct dm_hasher {
    rolling_hash<997137961, 753> h1;
    rolling_hash<1003911991, 467> h2;

    void build(const char *str) {
        h1.build(str); h2.build(str);
    }

    uint64_t operator() (int l, int r) {
        return uint64_t(h1(l, r)) << 32 | h2(l, r);
    }
} hasher;

int n;
vector<pair<int, int>> pos;
int ans[1 << 20];

int bsearch(int l, int r, int k) {
    while (l < r) {
        int mid = (l + r) / 2;
        int ll, rr; tie(ll, rr) = pos[mid];
        if (hasher(ll + k, rr) == hasher(ll, rr - k)) l = mid + 1; else r = mid;
    }
    return l;
}

int main() {
    cin >> n;
    list<char> ch;
    int nl = 0, nr = 0;
    pos.emplace_back(0, 0);
    for (int i = 0; i < n; i++) {
        string d, note; cin >> d >> note;
        if (note == "sol") note[0] = 'z';
        if (d == "a") {
            ch.push_back(note[0]);
            nr++;
        } else {
            ch.push_front(note[0]);
            nl++;
        }
        pos.emplace_back(nl, nr);
    }
    hasher.build(string(ch.begin(), ch.end()).c_str());
    for (auto& p : pos) p.first = nl - p.first, p.second += nl;
    for (int i = 1; i <= n; i++) {
        ans[i]++;
        ans[bsearch(i, n + 1, i)]--;
    }
    partial_sum(ans + 1, ans + n + 1, ans + 1);
    for (int i = 1; i <= n; i++) cout << ans[i] << endl;
    return 0;
}

#include "lcs.h"
using namespace std;

#define N 110

void find_permutation(int n, int res[]) {
    if (n == 1) {
        res[0] = 1;
        return;
    }
    int a[N];
    //init
    a[0] = 1;
    for (int i = 1; i < n; i++) {
        a[i] = 2;
    }
    int k = 0;
    int t = get_lcs(n, a);
    if (t == 2) {
        res[k++] = 1;
        res[k++] = 2;
    } else {
        res[k++] = 2;
        res[k++] = 1;
    }
    //check
    auto chk = [&](int m, int x) -> bool {
        a[0] = res[m];
        for (int i = 1; i < n; i++) a[i] = x;
        int t = get_lcs(n, a);
        if (t == 2) return true;
        return false;
    };
    //3 ~ n
    for (int i = 3; i <= n; i++) {
        //[0, k)
        int l = 0, r = k, mid;
        while (l < r) {
            mid = (l + r) >> 1;
            if (chk(mid, i)) r = mid;
            else l = mid + 1;
        }
        if (r == k) {
            res[k++] = i;
        } else {
            for (int j = k; j > r; j--) res[j] = res[j - 1];
            res[r] = i;   
            ++k;
        }
    }
}

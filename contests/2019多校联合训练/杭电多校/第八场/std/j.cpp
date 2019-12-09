#include <bits/stdc++.h>
using namespace std;
 
#ifdef __LOCAL_DEBUG__
# define _debug(fmt, ...) fprintf(stderr, "\033[94m%s " fmt "\n\033[0m", \
  __func__, ##__VA_ARGS__)
#else
# define _debug(...) ((void) 0)
#endif
 
#define rep(i, n) for (int i=0; i<(n); i++)
#define Rep(i, n) for (int i=1; i<=(n); i++)
#define range(x) (x).begin(), (x).end()
typedef long long LL;
typedef unsigned long long ULL;
 
int T;
int n, d;
char nm[2000005][12];
int gts[2000005], fs[2000005];
int arr[2000005];
 
bool cmp(int l, int r) {
  if (gts[l] != gts[r]) {
    return gts[l] > gts[r];
  } else {
    return fs[l] < fs[r];
  }
}
 
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &d);
    rep (i, n) {
      scanf("%s%d%d", nm[i], gts + i, fs + i);
      arr[i] = i; 
    }
    int nn = n * d;
    if (nn % 10 == 5) {
      int x = nn / 10;
      nth_element(arr, arr+x, arr+n, cmp);
      printf("%s\n", nm[arr[x]]);
    } else { 
      printf("Quailty is very great\n");
    }
  }
  return 0;
}

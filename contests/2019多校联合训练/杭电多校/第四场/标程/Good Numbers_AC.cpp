#include <bits/stdc++.h>
using namespace std;

const int P = 1e9 + 9;
const int W1 = 115381398;
const int W2 = 884618610;

int modExp(int a, int n, int p) {
	int ret = 1;
	for (; n; n >>= 1, a = (long long)a * a % p) if (n & 1) ret = (long long)ret * a % p;
	return ret;
}

void trans(int *a, int n) {
	if (n == 1) return;
	int m = n / 3;
	trans(a, m);
	trans(a + m, m);
	trans(a + m + m, m);
	for (int *z = a + m + m, *y = a + m, *x = a, i = 0; i < m; i++, x++, y++, z++) {
		unsigned a = *x, b = *y, c = *z;
		*x = (a + b + c) % P;
		*y = (a + (long long)W1 * b + (long long)W2 * c) % P;
		*z = (a + (long long)W2 * b + (long long)W1 * c) % P;
	}
}

void untrans(int *a, int n) {
	if (n == 1) return;
	int m = n / 3;
	for (int *z = a + m + m, *y = a + m, *x = a, i = 0; i < m; i++, x++, y++, z++) {
		unsigned a = *x, b = *y, c = *z;
		*x = (a + b + c) % P;
		*y = (a + (long long)W2 * b + (long long)W1 * c) % P;
		*z = (a + (long long)W1 * b + (long long)W2 * c) % P;
	}
	untrans(a, m);
	untrans(a + m, m);
	untrans(a + m + m, m);
}

int a[8][6561];
int b[8][6561];
int c[8][6561];

long long __a[8][6561];
long long __b[8][6561];

int pw[8];

int main() {
	long long N;
	int S;
	for (int i = 0; i < 8; i++) pw[i] = (i == 0 ? 1 : pw[i - 1] * 3);
	while (cin >> N >> S) {
		int mul = 1;
		for (int i = 59; i >= 0; i--) {
			long long M = N >> i;
			if (M == 0) continue;
			if (M == 1) {
				for (int j = 0; j < S; j++) {
					memset(a[j], 0, sizeof a[j]);
					memset(b[j], 0, sizeof b[j]);
				}
				for (int j = 1; j < 8; j++) a[j % S][pw[j]]++, b[j % S][pw[j]]++;
				a[0][1] = 1;
				for (int j = 0; j < S; j++) {
					trans(a[j], 6561);
					trans(b[j], 6561);
					memcpy(c[j], a[j], sizeof a[j]);
				}
				mul = 8 % S;
			} else {
				for (int j = 0; j < S; j++) {
					memset(__a[j], 0, sizeof __a[j]);
					memset(__b[j], 0, sizeof __b[j]);
				}
				for (int j = 0; j < S; j++) {
					for (int k = 0; k < S; k++) {
						int l = (j * mul + k) % S;
						for (int i = 0; i < 6561; i++) {
							__a[l][i] += (long long)a[j][i] * a[k][i];
							__b[l][i] += (long long)b[j][i] * a[k][i];
						}
					}
				}
				for (int j = 0; j < S; j++) {
					for (int i = 0; i < 6561; i++) {
						a[j][i] = __a[j][i] % P;
						b[j][i] = __b[j][i] % P;
					}
				}
				mul = mul * mul % S;
				if (M + 1 & 1) continue;
				for (int j = 0; j < S; j++) {
					memset(__a[j], 0, sizeof __a[j]);
					memset(__b[j], 0, sizeof __b[j]);
				}
				for (int j = 0; j < S; j++) {
					for (int k = 0; k < S; k++) {
						int l = (j * 8 + k) % S;
						for (int i = 0; i < 6561; i++) {
							__a[l][i] += (long long)a[j][i] * c[k][i];
							__b[l][i] += (long long)b[j][i] * c[k][i];
						}
					}
				}
				for (int j = 0; j < S; j++) {
					for (int i = 0; i < 6561; i++) {
						a[j][i] = __a[j][i] % P;
						b[j][i] = __b[j][i] % P;
					}
				}
				mul = mul * 8 % S;
			}
		}
		int R = modExp(6561, P - 2, P);
		for (int i = 0; i < 6561; i++) b[0][i] = (long long)b[0][i] * R % P;
		untrans(b[0], 6561);
		printf("%d\n", b[0][0]);
	}
	return 0;
}

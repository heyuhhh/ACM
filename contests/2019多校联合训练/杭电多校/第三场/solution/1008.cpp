	#include <bits/stdc++.h>
	using namespace std;

	const int N = 1e5 + 10;
	const int M = 1e5 + 10;
	const int K = (1 << 21) + 5;

	int block;
	struct Q { int st, en, t, idx; } q[M];
	long long ans[M];
	bool operator < (Q a, Q b) {
		if (a.st / block != b.st / block) return a.st < b.st;
		if (a.en / block != b.en / block) return a.en < b.en;
		return a.t < b.t;
	}

	long long sum, cnt[K];
	int a[N], b[N], p[N];
	inline void add (int pos) { sum += cnt[b[pos]]++; }
	inline void sub (int pos) { sum -= --cnt[b[pos]]; }
	inline void upd (int i, int t) {
		if (q[i].st <= p[t] && p[t] <= q[i].en) sub(p[t]);
		b[p[t]] ^= a[p[t]];		
		swap(a[p[t]], a[p[t] + 1]);
		b[p[t]] ^= a[p[t]];
		if (q[i].st <= p[t] && p[t] <= q[i].en) add(p[t]);	
	}

	void MO (int n, int m) {
		block = max(10, (int)pow(n, 2. / 3));
		sort(q + 1, q + m + 1);
		sum = 0;
		int st = 0, en = -1, t = 0;
		for (int i = 1; i <= m; i++) {
			while (st < q[i].st) sub(st ++);
			while (st > q[i].st) add(-- st);
			while (en < q[i].en) add(++ en);
			while (en > q[i].en) sub(en --);
			while (t < q[i].t) upd(i, ++ t);
			while (t > q[i].t) upd(i, t --);
			ans[q[i].idx] = 1ll * (en - st) * (en - st + 1) / 2 - sum;
		}
	}

	void run (void) {
		// freopen("00.in", "r", stdin);
		// freopen("00.out", "w", stdout);

		int n, m;
		while(~scanf("%d%d", &n, &m)) {
			memset(cnt, 0, sizeof(cnt));

			for (int i = 1; i <= n; i++) {
				scanf("%d", a + i);
				b[i] = b[i - 1] ^ a[i];
			}
			int qcnt = 0, kcnt = 0, opt, l, r, x;
			for (int i = 1; i <= m; i++) {
				scanf("%d", &opt);
				if (opt == 1) {
					scanf("%d%d", &l, &r);
					q[++qcnt] = { l - 1, r, kcnt, qcnt };
				} else {
					scanf("%d", &x);
					p[++kcnt] = x;
				}
			}
			MO(n, qcnt);
			for (int i = 1; i <= qcnt; i++) {
				printf("%lld\n", ans[i]);
			}
		}
	}

	int main (void) {
		run();
	}
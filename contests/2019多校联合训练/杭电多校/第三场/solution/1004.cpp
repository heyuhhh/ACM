#include<bits/stdc++.h>
using namespace std;
const long long llINF = 9223372036854775807;
const int INF = 2147483647;
const int maxn = 3e5 + 7;
const int mod = 1e9 + 7;

/*
  题意:n个数,连续的一段分为一份,总共分为k份,要求每份和的最大值尽量小
  1<=n<=2e5,-1e9<=ai<=1e9,1<=k<=n
  note:不一定分完
*/

int T;
int n, k;
long long a[maxn], pre[maxn];
long long b[maxn];
long long ans = llINF;
int rk[maxn];
int num[maxn];

struct SegmentTree
{
	int l, r;
	int f;
} tree[maxn << 2];

void push_up(int root)
{
	tree[root].f = max(tree[root << 1].f, tree[root << 1 | 1].f);
}

void build(int root, int l, int r)
{
	tree[root].l = l;
	tree[root].r = r;
	if (l == r)
	{
		tree[root].f = -1000000000;
		return;
	}
	else
	{
		int mid = (l + r) >> 1;
		build(root << 1, l, mid);
		build(root << 1 | 1, mid + 1, r);
		push_up(root);
	}
	return;
}

int query(int root, int l, int r)
{
	if (l <= tree[root].l && r >= tree[root].r)
		return tree[root].f;
	int res = -INF;
	int mid = (tree[root].l + tree[root].r) >> 1;
	if (l <= mid)
		res = max(res, query(root << 1, l, r));
	if (r > mid)
		res = max(res, query(root << 1 | 1, l, r));
	return res;
}

void change(int root, int x, int v)
{
	if (tree[root].l == tree[root].r)
	{
		tree[root].f = v;
		return;
	}
	int mid = (tree[root].l + tree[root].r) >> 1;
	if (x <= mid)
		change(root << 1, x, v);
	else
		change(root << 1 | 1, x, v);
	push_up(root);
}

bool check(long long mid)
{
	build(1, 0, n + 1);
	/*
	dp[i]表示前i个数最多能分成几段
	for (int i = 1; i <= n; i++)
	{
		dp[i] =max(dp[j]) + 1;
		(sum[i]-sum[j]<=mid)
		sum[j]>=sum[i]-mid
	}
	*/
	change(1, rk[0], 0);

	for (int i = 1; i <= n; i++)
	{
		int p = lower_bound(b, b + 1 + n, pre[i] - mid) - b;
		change(1, rk[i], query(1, p, n + 1) + 1);
	}

	if (query(1, 0, n) >= k)
	{
		ans = min(ans, mid);
		return true;
	}
	return false;
}

void init()
{
	ans = llINF;
	memset(pre, 0, sizeof(pre));
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(rk, 0, sizeof(rk));
	memset(num, 0, sizeof(num));
	memset(tree, 0, sizeof(tree));
}

int main()
{
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);	
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &k);

		init();

		for (int i = 1; i <= n; i++)
			scanf("%lld", &a[i]);
		for (int i = 1; i <= n; i++)
			pre[i] = pre[i - 1] + a[i];
		//诡异的离散化
		for (int i = 0; i <= n; i++)
			b[i] = pre[i];
		sort(b, b + n + 1);
		for (int i = 0; i <= n; i++)
		{
			int tmp = lower_bound(b, b + 1 + n, pre[i]) - b;
			rk[i] = tmp + num[tmp];
			num[tmp]++;
		}

		long long L = -1e15, R = 1e15;
		while (L <= R)
		{
			long long mid = (L + R) >> 1;
			if (check(mid))
				R = mid - 1;
			else
				L = mid + 1;
		}
		printf("%lld\n", ans);
	}
	return 0;
}


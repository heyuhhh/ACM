//author Forsaken
#define Hello the_cruel_world!
#pragma GCC optimize(2)
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<utility>
#include<cmath>
#include<unordered_map>
#define FRIN freopen("C:\\Users\\Administrator.MACHENI-KA32LTP\\Desktop\\1.in", "r", stdin)
#define FROUT freopen("C:\\Users\\Administrator.MACHENI-KA32LTP\\Desktop\\1.out", "w", stdout)
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define outd(x) printf("%d\n", x)
#define outld(x) printf("%lld\n", x)
#define il inline
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int maxn = 5e6;
const int maxm = 200;
const int INF = 0x7fffffff;
const int mod = 1e9 + 7;
const double eps = 1e-7;
const double Pi = acos(-1.0);
il int read_int() {
	char c;
	int ret = 0, sgn = 1;
	do { c = getchar(); } while ((c < '0' || c > '9') && c != '-');
	if (c == '-') sgn = -1; else ret = c - '0';
	while ((c = getchar()) >= '0' && c <= '9') ret = ret * 10 + (c - '0');
	return sgn * ret;
}
il ll read_ll() {
	char c;
	ll ret = 0, sgn = 1;
	do { c = getchar(); } while ((c < '0' || c > '9') && c != '-');
	if (c == '-') sgn = -1; else ret = c - '0';
	while ((c = getchar()) >= '0' && c <= '9') ret = ret * 10 + (c - '0');
	return sgn * ret;
}
il ll quick_pow(ll base, ll index) {
	ll res = 1;
	while (index) {
		if (index & 1)res = res * base % mod;
		base = base * base % mod;
		index >>= 1;
	}
	return res;
}

//拉格朗日插值
ll fac[maxm + 5], inv[maxm + 5], pre[maxm + 5], suf[maxm + 5], sum[maxm + 5], n;
int k;
ll cal(ll n, int k) {
	if (n <= k + 2)return sum[n];
	pre[0] = suf[0] = 1;
	for (int i = 1; i <= k + 2; ++i) {
		pre[i] = pre[i - 1] * ((n - i) % mod) % mod;
		suf[i] = suf[i - 1] * ((n + i - k - 3) % mod) % mod;
	}
	ll res = 0;
	for (int i = 1; i <= k + 2; ++i) {
		ll s = sum[i] * pre[i - 1] % mod * suf[k - i + 2] % mod * inv[i - 1] % mod * inv[k + 2 - i] % mod;
		if ((k + 2 - i) & 1)s = -s;
		res += s;
		res = (res % mod + mod) % mod;
	}
	return res;
}

//线性筛
bool is_prime[maxn + 5];
int prime[maxn + 5], cnt, tot;
ll phi[maxn + 5], sp[maxn + 5];
void init(int n, int k) {
	for (int i = 2; i <= n; ++i)is_prime[i] = true;
	phi[1] = 1;
	for (int i = 2; i <= n; ++i) {
		if (is_prime[i])prime[++cnt] = i, sp[cnt] = quick_pow(i, k), phi[i] = i - 1;
		for (int j = 1; j <= cnt && i * prime[j] <= n; ++j) {
			is_prime[i * prime[j]] = false;
			if (i % prime[j]) phi[i * prime[j]] = phi[i] * phi[prime[j]];
			else {
				phi[i * prime[j]] = phi[i] * prime[j];
				break;
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		phi[i] = (phi[i] * i % mod * i % mod + phi[i - 1]) % mod;
		sp[i] = (sp[i] + sp[i - 1]) % mod;
	}
}

//杜教筛
unordered_map<ll, ll> sumdu;
ll inv2, inv6;
il ll Sum_cubic(ll n) {
	return (n * (n + 1) % mod * inv2 % mod) * (n * (n + 1) % mod * inv2 % mod) % mod;
}
il ll Sum_square(ll n) {
	return n * (n + 1) % mod * (2 * n + 1) % mod * inv6 % mod;
}
ll Sum_du(ll n) {
	if (n <= maxn)return phi[n];
	if (sumdu.count(n))return sumdu[n];
	ll res = 0;
	for (ll l = 2, r; l <= n; l = r + 1) {
		r = n / (n / l);
		res += (Sum_square(r % mod) - Sum_square((l - 1) % mod)) * Sum_du(n / l) % mod;
		res %= mod;
	}
	return sumdu[n] = (Sum_cubic(n % mod) - res) % mod;
}

//Min_25筛
ll g[maxn + 5], v[maxn + 5];
int id1[maxn + 5], id2[maxn + 5], m, block;
void Min25() {
	m = 0;
	block = sqrt(n);
	for (ll l = 1, r; l <= n; l = r + 1) {
		r = n / (n / l);
		v[++m] = n / l;
		if (v[m] <= block)id1[v[m]] = m;
		else id2[r] = m;
		g[m] = cal(v[m], k) - 1;
	}
	tot = lower_bound(prime + 1, prime + 1 + cnt, block) - prime;
	for (int i = 1; i <= tot; ++i) {
		for (int j = 1; j <= m && 1ll * prime[i] * prime[i] <= v[j]; ++j) {
			int id = (v[j] / prime[i] <= block) ? id1[v[j] / prime[i]] : id2[n / (v[j] / prime[i])];
			g[j] -= (sp[i] - sp[i - 1]) * (g[id] - sp[i - 1]) % mod;
			g[j] %= mod;
		}
	}
}

int main()
{
	inv2 = quick_pow(2, mod - 2), inv6 = quick_pow(6, mod - 2);
	for (int t = read_int(); t > 0; --t) {
		n = read_ll(), k = read_int() + 1;
		cnt = 0;
		init(maxn, k);
		fac[0] = fac[1] = inv[0] = inv[1] = sum[1] = 1;
		for (int i = 2; i <= k + 2; ++i) {
			sum[i] = (sum[i - 1] + quick_pow(i, k)) % mod;
			fac[i] = fac[i - 1] * i % mod;
			inv[i] = (mod - (mod / i)) * inv[mod % i] % mod;
		}
		for (int i = 1; i <= k + 2; ++i)inv[i] = inv[i] * inv[i - 1] % mod;
		Min25();
		ll res = 0;
		for (ll l = 1, r; l <= n; l = r + 1) {
			r = n / (n / l);
			int p1, p2;
			if (r <= block)p2 = id1[r];
			else p2 = id2[n / r];
			if (l - 1 <= block)p1 = id1[l - 1];
			else p1 = id2[n / (l - 1)];
			res += (g[p2] - g[p1]) % mod * Sum_du(n / l) % mod;
			res %= mod;
		}
		if (res < 0)res += mod;
		outld(res);
	}
	return 0;
}
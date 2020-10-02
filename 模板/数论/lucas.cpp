// lucas定理，用于快速求解大组合数在模意义下的答案

// 当模数为质数时，组合数那么可以拆分为十进制下每一位对应组合数的乘积
long long Lucas(long long n, long long m, long long p) {
  if (m == 0) return 1;
  return (C(n % p, m % p, p) * Lucas(n / p, m / p, p)) % p;
}

// 当模数不为质数时，先将模数拆分为若干个质因子的乘积，然后只考虑组合数在模p^t下的答案，最后通过excrt合并
// 之后考虑 n!,m!,(n-m)! 在模 p^t 意义下的答案即可
// 以 n! 为例，那么把 p 的倍数单独拿出来，并都提取一个 p 出来，那么后面相当于 (n/p)! 的一个子问题
// 前面剩下的则是以 p^t(也可以说是p)为周期的，那么可以O(p^t)预处理后直接计算。
// 注意：预处理时不用再把p的倍速给算进去。
ll calc(ll n, ll x, ll P) {
  if (!n) return 1;
  ll s = 1;
  for (int i = 1; i <= P; i++)
    if (i % x) s = s * i % P;
  s = qpow(s, n / P, P);
  for (int i = n / P * P + 1; i <= n; i++)
    if (i % x) s = s * i % P;
  // s：前半部分的结果，忽略x的贡献
  return s * calc(n / x, x, P) % P;
}
ll multilucas(ll m, ll n, ll x, ll P) {
  int cnt = 0;
  for (int i = m; i; i /= x) cnt += i / x;
  for (int i = n; i; i /= x) cnt -= i / x;
  for (int i = m - n; i; i /= x) cnt -= i / x;
  // 将质因子x的贡献单独拿到外面计算，之后就不考虑x的贡献了
  return qpow(x, cnt, P) % P * calc(m, x, P) % P * inverse(calc(n, x, P), P) %
         P * inverse(calc(m - n, x, P), P) % P;
}
ll exlucas(ll m, ll n, ll P) {
  int cnt = 0;
  ll p[20], a[20];
  for (ll i = 2; i * i <= P; i++) {
    if (P % i == 0) {
      p[++cnt] = 1;
      while (P % i == 0) p[cnt] = p[cnt] * i, P /= i;
      a[cnt] = multilucas(m, n, i, p[cnt]);
    }
  }
  if (P > 1) p[++cnt] = P, a[cnt] = multilucas(m, n, P, P);
  // 中国剩余定理合并得到答案
  return CRT(cnt, a, p);
}
// 广义五边形数 q[i]=(3i^2[+-]i) / 2

// 正整数拆分的生成函数 等于 欧拉函数的倒数 
// p[n]=\sum_i (-1)^{i-1} p(n-q_i)
// p[n]=p[n-1]+p[n-2]-p[n-5]-p[n-7]...
// p[n]表示n的正整数拆分数 
// 时间复杂度为 O(n\sqrt{n}) 
void init_p(int n, int* p) {
    for (int i = 0; i <= n; i++) {
        p[i] = 0;
    }
    auto P = [&] (int i) {
        return MP(i * (3 * i - 1) / 2, i * (3 * i + 1) / 2);
    };
    p[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1;; j++) {
            pii val = P(j);
            if (val.fi > i) break;
            int t = p[i - val.fi];
            if (val.se <= i) {
                t += p[i - val.se];
                if (t >= MOD) t -= MOD;
            }
            if (!(j & 1)) p[i] = (p[i] + MOD - t) % MOD;
            else p[i] = (p[i] + t) % MOD;
        }
    }
} 
// 快速莫比乌斯变化,即f变为f的子集和
// 之后f'*g'再通过逆变化回去就是子集并的卷积
void FMT(int *f, int n, int opt) {
    for (int j = 0; j < n; ++j)
        for (int i = 0; i < (1 << n); ++i) if (i >> j & 1)
            f[i] += opt * f[i ^ (1 << j)];
}
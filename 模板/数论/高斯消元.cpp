// 高斯消元浮点数
// a: 系数矩阵 b: 常数列 x: 答案列
double x[N];
void Gauss(double a[][N], double* b, int n) {
    for (int i = 1; i <= n; i++) {
        int p = i;
        for (int k = i + 1; k <= n; k++) {
            if (fabs(a[k][i]) > fabs(a[p][i])) p = k;
        }
        if (i != p) {
            swap(a[i], a[p]), swap(b[i], b[p]);
        }
        for (int k = i + 1; k <= n; k++) {
            double d = a[k][i] / a[i][i];
            b[k] -= d * b[i];
            for (int j = 1; j <= n; j++) {
                a[k][j] -= d * a[i][j];
            }
        }
    }
    // 回代 
    for (int i = n; i >= 1; i--) {
        for (int j = i + 1; j <= n; j++) b[i] -= x[j] * a[i][j];
        x[i] = b[i] / a[i][i];
    }
}
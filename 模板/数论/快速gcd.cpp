for (int i = 1; i <= a; i++) {
    for (int j = 1; j <= b; j++) {
        if (!Gcd[i][j]) {
            for (int k = 1; k * i <= a && k * j <= b; k++)
                Gcd[k * i][k * j] = k, Lcm[k * i][k * j] = i * j * k;
        }
    }
}
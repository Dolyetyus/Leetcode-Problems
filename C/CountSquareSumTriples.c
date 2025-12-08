int countTriples(int n) {
    int a = 1;
    int b = 1;
    int ret = 0;

    for (int a = 1; (a*a + b*b) <= n*n; a++) {
        for (int b = 1; (a*a + b*b) <= n*n; b++) {
            int sum = a*a + b*b;
            int sqrt_sum = (int)sqrt(sum);
            if (sqrt_sum * sqrt_sum == sum) ret++;
        }
    }

    return ret;
}

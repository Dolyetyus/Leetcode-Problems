int numOfWays(int n) {
    long long a[n], b[n];
    a[0] = 6;
    b[0] = 6;

    for (int i = 1; i<n; i++) {
        a[i] = (2*a[i-1] + 2*b[i-1]) % 1000000007;
        b[i] = (2*a[i-1] + 3*b[i-1]) % 1000000007;
    }

    return (a[n-1] + b[n-1]) % 1000000007;
}

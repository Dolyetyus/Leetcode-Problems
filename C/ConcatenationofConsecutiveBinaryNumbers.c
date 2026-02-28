int concatenatedBinary(int n){
    long long ret = 0;
    int bitLength = 0;

    for (int i = 1; i<=n; i++) {
        if ((i & (i-1)) == 0) bitLength++;

        ret = ((ret << bitLength) | i) % 1000000007;
    }

    return ret;
}

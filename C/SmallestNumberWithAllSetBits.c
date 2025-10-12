int smallestNumber(int n) {
    int ret = 1;
    while (ret<=n) ret *= 2;
    return ret-1;
}

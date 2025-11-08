int minimumOneBitOperations(int n) {
    int len = log2(n)+1;
    int prev = 0;

    for (int i = 0; i<len; i++) {
        int bit = (n & (1<<i));
        if (bit != 0) {
            bit = bit*2-1;
            prev = abs(bit - prev);
        }
    }

    return prev;
}

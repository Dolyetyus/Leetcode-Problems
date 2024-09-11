int minBitFlips(int start, int goal) {
    int res = start ^ goal;

    unsigned int count = 0;
    while (res) {
        count += res & 1;
        res >>= 1;
    }

    return count;
}

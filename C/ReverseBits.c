int reverseBits(int n) {
    uint32_t ret = 0;
    for (int i = 0; i<32; i++) {
        ret <<= 1;
        ret |= (n & 1);
        n >>= 1;
    }
    return ret;
}

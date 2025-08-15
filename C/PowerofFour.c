bool isPowerOfFour(int n) {
    if (n==1) return true;
    else if (n<4) return false;

    int zeroes = 0;
    while (n > 1) {
        if (n & 1) return false;
        zeroes++;
        n >>= 1;
    }

    return (zeroes%2==0);
}

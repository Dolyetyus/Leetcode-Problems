int mirrorDistance(int n) {
    int num = n;
    int rev = 0;

    while (num>0) {
        rev *= 10;
        rev += num%10;
        num /= 10;
    }

    return abs(n-rev);
}

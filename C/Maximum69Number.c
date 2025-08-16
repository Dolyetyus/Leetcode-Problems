int maximum69Number (int num) {
    int ret = num;
    int rem = 0;
    int digit = 0;
    int increase = 0;

    while (ret>0) {
        rem = ret%10;
        digit++;
        if (rem==6) increase = digit;
        ret /= 10;
    }

    return num+3*pow(10, increase-1);
}

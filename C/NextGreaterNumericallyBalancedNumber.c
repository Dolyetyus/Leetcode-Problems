int nextBeautifulNumber(int n) {
    if (n == 0) return 1;
    int* freqArr = calloc(10, sizeof(int));
    n++;
    
    while (true) {
        int num = n;
        while (num>0) {
            freqArr[num%10]++;
            num/=10;
        }

        bool ret = true;
        for (int i = 0; i<10; i++) {
            if (freqArr[i]!=i && freqArr[i]!=0) {
                ret = false;
                break;
            }
        }

        if (ret) return n;
        memset(freqArr, 0, 10*sizeof(int));
        n++;
    }

    return 0;
}

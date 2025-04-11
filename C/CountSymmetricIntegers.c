int countDigits(int n) {
    int ret = 0;
    while (n>0){
        ret++;
        n /= 10;
    }
    return ret;
}

int countSymmetricIntegers(int low, int high) {
    int ret = 0;

    while (low<=high){
        int digits = countDigits(low);

        if (digits == 1) {
            low = 10;
            continue;
        }
        else if (digits == 3) {
            low = 1000;
            continue;
        }
        else if (digits == 5) {
            low = 100000;
            continue;
        }

        int num = low;
        int processed = 1;
        int sum1 = 0;
        int sum2 = 0;
        while (num>0){
            if (processed<=digits/2) sum1 += num%10;
            else sum2 += num%10;

            num /= 10;
            processed++;
        }

        if (sum1==sum2) ret++;

        low++;
    }

    return ret;
}

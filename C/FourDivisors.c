int sumOfDivisors(int num) {
    int total = 0;
    int divisors = 0;

    for (int i = 1; i*i <= num; i++) {
        if (num%i == 0) {
            if (i*i == num) {
                total += i;
                divisors++;
            }
            else {
                total += (i + num/i);
                divisors+=2;
            }
        }
    }

    if (divisors==4) return total;
    return 0;
}

int sumFourDivisors(int* nums, int numsSize) {
    int ret = 0;

    for (int i = 0; i<numsSize; i++) {
        ret += sumOfDivisors(nums[i]);
    }

    return ret;
}

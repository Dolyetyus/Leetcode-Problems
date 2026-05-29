int digits(int num) {
    int ret = 0;

    while (num>0) {
        ret += num%10;
        num /= 10;
    }

    return ret;
}

int minElement(int* nums, int numsSize) {
    int ret = 9999999;

    for (int i = 0; i<numsSize; i++) {
        ret = fmin(ret, digits(nums[i]));
    }

    return ret;
}

int countPartitions(int* nums, int numsSize) {
    int prefix[numsSize];
    int suffix[numsSize];
    int ret = 0;

    prefix[0] = nums[0];
    suffix[numsSize-1] = nums[numsSize-1];
    for (int i = 1; i<numsSize; i++) {
        prefix[i] = prefix[i-1]+nums[i];
        suffix[numsSize-1-i] = suffix[numsSize-i]+nums[numsSize-1-i];
    }

    for (int i = 0; i<numsSize-1; i++) {
        if ((prefix[i]-suffix[i+1])%2 == 0) ret++;
    } 

    return ret;
}

int minimumOperations(int* nums, int numsSize) {
    int ret = 0;
    for (int i = 0; i<numsSize; i++) {
        if (nums[i]%3 != 0) ret++;
    }

    return ret;
}

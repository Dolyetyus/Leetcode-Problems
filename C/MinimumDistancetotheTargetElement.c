int getMinDistance(int* nums, int numsSize, int target, int start) {
    int ret = 999999;

    for (int i = 0; i<numsSize; i++) {
        if (nums[i] == target) ret = fmin(ret, abs(i-start));
    }

    return ret;
}

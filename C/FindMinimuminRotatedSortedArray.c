int findMin(int* nums, int numsSize) {
    int ret = 5001;

    for (int i = 0; i<numsSize; i++) {
        ret = fmin(nums[i], ret);
    }

    return ret;
}

int findMin(int* nums, int numsSize) {
    int ret = 5001;
    
    for (int i = 0; i<numsSize; i++) {
        ret = fmin(ret, nums[i]);
    }

    return ret;
}

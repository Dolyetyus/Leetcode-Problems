int countPairs(int* nums, int numsSize, int k) {
    int ret = 0;

    for (int i = 0; i<numsSize; i++) {
        for (int ii = i+1; ii<numsSize; ii++) {
            if (nums[i]==nums[ii] && (i*ii)%k == 0) ret++;
        }
    }

    return ret;
}

int minCapability(int* nums, int numsSize, int k) {
    int l = 1, r = 1000000000;
    while (l < r) {
        int mid = (l + r) / 2, take = 0;
        for (int i = 0; i < numsSize && take < k; ++i) {
            take += nums[i] <= mid;
            i += nums[i] <= mid;
        }
        if (take < k) l = mid + 1;
        else r = mid;
    }
    return l;
}

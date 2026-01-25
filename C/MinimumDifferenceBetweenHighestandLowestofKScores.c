int compare(const void *a, const void *b) {
    int int_a = *((int*)a);
    int int_b = *((int*)b);

    if (int_a == int_b) return 0;
    else if (int_a < int_b) return -1;
    else return 1;
}

int minimumDifference(int* nums, int numsSize, int k) {
    int ret = 999999999;
    qsort(nums, numsSize, sizeof(int), compare);

    int left = 0; int right = k-1;
    while (right<numsSize) {
        ret = fmin(ret, nums[right]-nums[left]);
        left++;
        right++;
    }

    return ret;
}

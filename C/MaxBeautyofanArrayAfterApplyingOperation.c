int compare(const void* a, const void* b) {
   return (*(int*)a - *(int*)b);
}

int maximumBeauty(int* nums, int numsSize, int k) {
    int ret = 0;
    qsort(nums, numsSize, sizeof(int), compare);

    int right = 0;
    for (int left = 0; left < numsSize; left++) {
        while (nums[left]-nums[right] > 2*k) {
            right++;
        }
        int currentLen = left-right+1;
        if (currentLen > ret) ret = currentLen;
    }

    return ret;
}

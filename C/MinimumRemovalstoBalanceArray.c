int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int minRemoval(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), compare);

    int max_kept = 0;
    int j = 0;
    for (int i = 0; i<numsSize; i++) {
        while (j<numsSize && (long long)nums[j] <= (long long)k*nums[i]) j++;
        if (j-i > max_kept) max_kept = j-i;
    }

    return numsSize-max_kept;
}

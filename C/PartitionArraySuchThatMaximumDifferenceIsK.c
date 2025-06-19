int comp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}   

int partitionArray(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), comp);

    int ret = 0;
    int start = nums[0];
    for (int i = 0; i<numsSize; i++){
        if (nums[i]-start>k) {
            ret++;
            start = nums[i];
        }
    }

    return ret+1;
}

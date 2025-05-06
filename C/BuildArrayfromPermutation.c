int* buildArray(int* nums, int numsSize, int* returnSize) {
    int* ret = malloc(numsSize*sizeof(int));
    *returnSize = numsSize;

    for (int i = 0; i<numsSize; i++) {
        ret[i] = nums[nums[i]];
    }

    return ret;
}

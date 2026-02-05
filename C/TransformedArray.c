int* constructTransformedArray(int* nums, int numsSize, int* returnSize) {
    int* ret = malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    
    for (int i = 0; i<numsSize; i++) {
        ret[i] = nums[((i+nums[i])%numsSize + numsSize)%numsSize];
    }

    return ret;
}

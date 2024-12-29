int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int prefix[numsSize];
    int suffix[numsSize];

    prefix[0] = nums[0];
    suffix[numsSize-1] = nums[numsSize-1];

    for (int i = 1; i<numsSize; i++){
        prefix[i] = prefix[i-1]*nums[i];
        suffix[numsSize-1-i] = suffix[numsSize-i]*nums[numsSize-1-i];
    }

    nums[numsSize-1] = prefix[numsSize-2];
    nums[0] = suffix[1];
    for (int i = 1; i<numsSize-1; i++){
        nums[i] = prefix[i-1]*suffix[i+1];
    }

    return nums;
}

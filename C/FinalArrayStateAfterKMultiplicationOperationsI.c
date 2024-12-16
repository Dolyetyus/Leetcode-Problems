int* getFinalState(int* nums, int numsSize, int k, int multiplier, int* returnSize) {
    *returnSize = numsSize;
    
    while (k){
        int* min = &nums[0];
        for (int i = 1; i<numsSize; i++){
            if (nums[i]<*min) min = &nums[i];
        }

        *min *= multiplier;
        k--;
    }

    return nums;
}

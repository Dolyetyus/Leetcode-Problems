int* applyOperations(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int *ret = calloc(numsSize, sizeof(int));

    int index = 0;
    for (int i = 0; i<numsSize-1; i++){
        if (nums[i]==nums[i+1] && nums[i]!=0){
            ret[index] = nums[i]*2;
            nums[i+1] = 0;
            index++;
        }
        else if (nums[i]!=0) {
            ret[index] = nums[i];
            index++;
        }
    }

    if (nums[numsSize-1]!=0) ret[index] = nums[numsSize-1];

    return ret;
}

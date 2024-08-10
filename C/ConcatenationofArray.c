int* getConcatenation(int* nums, int numsSize, int* returnSize) {
    *returnSize = 2*numsSize;
    nums = realloc(nums, 2*numsSize*sizeof(int));
    
    for (int i = 0; i<numsSize; i++){
        nums[numsSize+i] = nums[i];
    }

    return nums;
}

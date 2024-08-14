int* buildArray(int* nums, int numsSize, int* returnSize) {
    int* temp = malloc(sizeof(int)*numsSize);
    *returnSize = numsSize;
    memcpy(temp, nums, sizeof(int)*numsSize);

    for (int i = 0; i<numsSize; i++){
        temp[i] = nums[nums[i]];
    }

    return temp;
}

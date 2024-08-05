int* shuffle(int* nums, int numsSize, int n, int* returnSize){
    int left = 0;
    int i = 0;
    int* ret = malloc(numsSize*sizeof(int));
    *returnSize = numsSize;

    while (n<numsSize){
        ret[i] = nums[left];
        i++;
        ret[i] = nums[n];
        i++;

        left++;
        n++;
    }

    return ret;
}

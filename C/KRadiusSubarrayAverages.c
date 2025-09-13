int* getAverages(int* nums, int numsSize, int k, int* returnSize) {
    int* ret = calloc(numsSize, sizeof(int));
    *returnSize = numsSize;

    long* prefix = calloc(numsSize+1, sizeof(long));
    prefix[0] = 0;
    prefix[1] = nums[0];
    for (int i = 1; i<numsSize; i++){
        prefix[i+1] = nums[i]+prefix[i];
    }

    for (int i = 0; i<numsSize; i++){
        if (i-k<0 || i+k>=numsSize) ret[i] = -1;
        else ret[i] = (prefix[i+k+1]-prefix[i-k])/(k*2+1);
    }

    return ret;
}

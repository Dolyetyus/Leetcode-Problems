int compare(const void *a, const void *b) {
    int int_a = *((int*)a);
    int int_b = *((int*)b);

    if (int_a == int_b) return 0;
    else if (int_a < int_b) return -1;
    else return 1;
}

int minPairSum(int* nums, int numsSize){
    int ret = 0;
    qsort(nums, numsSize, sizeof(int), compare);

    for (int i = 0; i<numsSize/2; i++) {
        ret = fmax(ret, nums[i]+nums[numsSize-i-1]);
    }

    return ret;
}

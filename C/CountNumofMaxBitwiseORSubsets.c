int countMaxOrSubsets(int* nums, int numsSize) {
    int ret = 0;
    int max = 0;

    for (int i = 0; i<numsSize; i++){
        max |= nums[i];
    }

    for (int i = 1; i < (1 << numsSize); i++) {
        int temp = 0;
        for (int j = 0; j < numsSize; j++) {
            if (i & (1 << j)) {
                temp |= nums[j];
            }
        }
        if (temp == max) ret++;
    }

    return ret;
}

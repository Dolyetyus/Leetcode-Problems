int simulate(int* nums, int direction, int pos, int numsSize, int nonZero) {
    while (true) {
        pos += direction;
        if (pos<0 || pos>=numsSize) {
            if (nonZero==0) return 1;
            return 0;
        }
        
        if (nums[pos]!=0) {
            nums[pos]--;
            if (nums[pos]==0) nonZero--;
            direction *= -1;
        }
    }
}

int countValidSelections(int* nums, int numsSize) {
    int ret = 0;
    int nonzero = 0;
    int* simArr = calloc(numsSize, sizeof(int));

    for (int n = 0; n<numsSize; n++) {
        if (nums[n]!=0) nonzero++;
    }

    for (int n = 0; n<numsSize; n++) {
        if (nums[n]==0) {
            memcpy(simArr, nums, numsSize*sizeof(int));
            ret += simulate(simArr, 1, n, numsSize, nonzero);
            memcpy(simArr, nums, numsSize*sizeof(int));
            ret += simulate(simArr, -1, n, numsSize, nonzero);
        }
    }

    return ret;
}

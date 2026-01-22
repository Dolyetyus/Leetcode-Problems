int isNonDecreasing(int* nums, int n) {
    for (int i = 1; i<n; i++) {
        if (nums[i]<nums[i-1]) return 0;
    }
    return 1;
}

int minimumPairRemoval(int* nums, int numsSize) {
    int ret = 0;

    while (!isNonDecreasing(nums, numsSize)) {
        int minSum = nums[0]+nums[1];
        int index = 0;

        for (int i = 1; i<numsSize-1; i++) {
            int sum = nums[i] + nums[i+1];
            if (sum < minSum) {
                minSum = sum;
                index = i;
            }
        }

        nums[index] = minSum;
        for (int i = index+1; i<numsSize-1; i++) {
            nums[i] = nums[i+1];
        }

        numsSize--;
        ret++;
    }

    return ret;
}

int rob(int* nums, int numsSize) {
    if (numsSize < 2) return nums[0];
    
    int* dp = calloc(numsSize, sizeof(int));
    int max = 0;
    dp[0] = nums[0];
    dp[1] = nums[1];

    for (int i = 2; i<numsSize; i++) {
        for (int n = 0; n<i-1; n++) {
            if (dp[n]>max) max = dp[n];
        }
        dp[i] = max + nums[i];
        max = 0;
    }

    if (dp[numsSize-1] > dp[numsSize-2]) return dp[numsSize-1];
    return dp[numsSize-2];
}

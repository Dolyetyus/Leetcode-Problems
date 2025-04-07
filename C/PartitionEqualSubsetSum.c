bool canPartition(int* nums, int numsSize) {
    int total = 0;
    for (int i = 0; i<numsSize; i++) total += nums[i];
    
    if (total%2==1 || numsSize<2) return false;

    int target = total / 2;
    
    bool* dp = (bool*)calloc(target + 1, sizeof(bool));
    dp[0] = true;
    
    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        for (int j = target; j >= num; j--) {
            if (dp[j - num]) dp[j] = true;
        }
    }
    
    bool result = dp[target];
    free(dp);
    return result;
}

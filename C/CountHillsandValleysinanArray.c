int countHillValley(int* nums, int numsSize) {
    int ret = 0;
    int left = -1;
    int right = -1;

    for (int i = 1; i<numsSize-1; i++){
        left = i-1;
        while (left>-1 && nums[left]==nums[i]) left--;
        if (left<0) continue;

        right = i+1;
        while (right<numsSize && nums[right]==nums[i]) right++;
        if (right>=numsSize) continue;

        if (nums[left] < nums[i] && nums[right] < nums[i]) ret++; 
        if (nums[left] > nums[i] && nums[right] > nums[i]) ret++;

        if (right>i+1) i = right-1;
    }

    return ret;
}

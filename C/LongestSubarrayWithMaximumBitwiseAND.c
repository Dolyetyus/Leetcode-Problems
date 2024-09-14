int longestSubarray(int* nums, int numsSize) {
    int count = 0;
    int max = 0;
    int currentCount = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > max) {
            max = nums[i];
            count = 1;
            currentCount = 1;
        } 
        else if (nums[i] == max) {
            currentCount++;
            if (currentCount > count) {
                count = currentCount;
            }
        } 
        else {
            currentCount = 0;
        }
    }

    return count;
}

int longestSubarray(int* nums, int numsSize) {
    int right = 0;
    int left = 0;
    int zero = 0;
    int ret = 0;

    while (right < numsSize) {
        if (nums[right] == 0) zero++;
        right++;

        while (zero > 1) {
            if (nums[left] == 0) zero--;
            left++;
        }

        if (right - left - 1 > ret) ret = right - left - 1;
    }

    return ret;
}

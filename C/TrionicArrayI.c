bool isTrionic(int* nums, int numsSize) {
    int mask = 0;
    if (nums[0] >= nums[1]) return false;

    for (int i = 1; i<numsSize; i++) {
        if (mask == 0) {
            if (nums[i] > nums[i-1]) continue;
            mask = 1;
        }
        if (mask == 1) {
            if (nums[i] < nums[i-1]) continue;
            mask = 2;
        }
        if (mask == 2) {
            if (nums[i] > nums[i-1]) continue;
            return false;
        }
    }

    return mask == 2;
}

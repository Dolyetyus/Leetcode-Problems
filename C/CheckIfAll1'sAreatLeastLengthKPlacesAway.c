bool kLengthApart(int* nums, int numsSize, int k) {
    int prev = -1;
    for (int i = 0; i<numsSize; i++) {
        if (nums[i] == 1) {
            if (prev>=0 && i-prev<=k) return false;
            prev = i;
        }
    }

    return true;
}

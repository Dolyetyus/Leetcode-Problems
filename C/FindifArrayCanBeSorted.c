int countBits(int n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

bool canSortArray(int* nums, size_t numsSize) {
    int prevMax = INT_MIN;
    int currMax = nums[0];
    int currMin = nums[0];
    int setBits = countBits(nums[0]);

    for (size_t i = 1; i < numsSize; i++) {
        if (setBits == countBits(nums[i])) {
            currMax = max(currMax, nums[i]);
            currMin = min(currMin, nums[i]);
        } 
        else {
            if (currMin < prevMax) return false;
            prevMax = currMax;
            setBits = countBits(nums[i]);
            currMin = nums[i];
            currMax = nums[i];
        }
    }

    return currMin > prevMax;
}

int findFinalValue(int* nums, int numsSize, int original) {
    bool set[1000];

    for (int i = 0; i<numsSize; i++) {set[nums[i]-1] = true;}
    
    while (original<=1000) {
        if (!set[original-1]) return original;
        original *= 2;
    }

    return original;
}

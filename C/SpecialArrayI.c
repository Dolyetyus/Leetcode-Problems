bool isArraySpecial(int* nums, int numsSize) {
    for (int i = 1; i<numsSize; i++){
        if (nums[i-1]%2==nums[i]%2) return false;
    }
    return true;
}

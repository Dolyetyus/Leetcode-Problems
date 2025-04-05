int subsetXORSum(int* nums, int numsSize) {
    int totalOR = 0;
    for (int i = 0; i < numsSize; i++)totalOR |= nums[i];
    
    return totalOR * (1 << (numsSize - 1));
}

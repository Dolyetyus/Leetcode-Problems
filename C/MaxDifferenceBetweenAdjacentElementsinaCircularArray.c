int maxAdjacentDistance(int* nums, int numsSize) {
    int max = 0;

    for (int i = 0; i<numsSize-1; i++){
        if (abs(nums[i]-nums[i+1])>max) max=abs(nums[i]-nums[i+1]);
    }

    if (abs(nums[0]-nums[numsSize-1])>max) max=abs(nums[0]-nums[numsSize-1]);

    return max;
}

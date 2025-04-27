int countSubarrays(int* nums, int numsSize) {
    int ret = 0;

    for (int i = 0; i<numsSize-2; i++){
        if (nums[i+1] == (nums[i]*2)+(nums[i+2]*2)) ret++;
    }

    return ret;
}

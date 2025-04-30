int findNumbers(int* nums, int numsSize) {
    int ret = 0;

    for (int i = 0; i<numsSize; i++) { 
        if ((nums[i]>9 && nums[i]<100) || (nums[i]>999 && nums[i]<10000) || nums[i]==100000) ret++;
    }

    return ret;
}

int minOperations(int* nums, int numsSize) {
    int i = 0;
    int ret = 0;
    while (i <= numsSize-3){
        if (nums[i]%2 == 0){
            ret++;
            for (int x = 0; x<3; x++) nums[i+x]++;
        }
        i++;
    }

    for (i; i<numsSize; i++){
        if (nums[i]%2 == 0) return -1;
    }

    return ret;
}

bool check(int* nums, int numsSize) {
    int found = 0;

    nums = realloc(nums, sizeof(int)*(numsSize+1));
    nums[numsSize] = nums[0];

    for (int i = 0; i<numsSize; i++){
        if (nums[i]>nums[i+1]){
            if (found) return false;
            found++;
        }
    }

    return true;
}

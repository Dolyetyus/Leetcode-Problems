int maxAscendingSum(int* nums, int numsSize) {
    int max = 0;
    int curr = nums[0];
    
    for (int i = 1; i<numsSize; i++){
        if (nums[i]<=nums[i-1]){
            if (curr>max) max = curr;
            curr = 0;
        }
        curr+=nums[i];
    }

    if (curr>max) max = curr;

    return max;
}

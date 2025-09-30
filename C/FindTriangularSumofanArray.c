int triangularSum(int* nums, int numsSize) {
    int n = numsSize;
    int temp = -1;
    while (n > 1) {
        for (int i = 0; i<n-1; i++) {
            if (i%2==0) temp = (nums[i]+nums[i+1])%10;
            else {
                nums[i] = (nums[i]+nums[i+1])%10;
                nums[i-1] = temp;
            }
        }
        if (n%2==0) nums[n-2] = temp;
        n--;
    }

    return nums[0];
}

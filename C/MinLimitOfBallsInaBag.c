int operationsNeeded(int* nums, int numsSize, int penalty) {
    int operations = 0;
    for (int i = 0; i < numsSize; i++) {
        operations += (nums[i]-1)/penalty;
    }
    return operations;
}

int minimumSize(int* nums, int numsSize, int maxOperations) {
    int left = 1;
    int right = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > right) right = nums[i];
    }

    while (left < right) {
        int mid = left + (right-left)/2;
        if (operationsNeeded(nums, numsSize, mid) <= maxOperations)
            right = mid;
        else
            left = mid+1;
    }

    return left;
}

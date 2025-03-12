int maximumCount(int* nums, int numsSize) {
    if (numsSize==1 && nums[0] == 0) return 0;
    if (numsSize==1) return 1;

    int left = 0;
    int right = numsSize-1;
    int mid = 0;

    while (left <= right) {
        mid = left + (right - left) / 2;

        if (nums[mid] < 0) left = mid + 1;
        else right = mid - 1;

    }
    int negativeCount = left;

    left = 0, right = numsSize-1;
    while (left <= right) {
        mid = left + (right - left) / 2;

        if (nums[mid] <= 0) left = mid + 1;
        else right = mid - 1;
    }
    int positiveCount = numsSize - left;

    if (negativeCount>positiveCount) return negativeCount;
    return positiveCount;
}

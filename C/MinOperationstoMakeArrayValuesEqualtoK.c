void insertionSortDesc(int* arr, int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }
}

int minOperations(int* nums, int numsSize, int k) {
    if (numsSize==1) {
        if (nums[0]==k) return 0;
        return (nums[0]-k > 0) ? 1 : -1;
    }

    insertionSortDesc(nums, numsSize);
    if (nums[0]<k) return -1;

    int ret = 0;
    int prev = -1;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == k) continue;
        if (nums[i] < k && i == numsSize-1) return -1;
        if (nums[i] != prev) {
            ret++;
            prev = nums[i];
        }
    }

    return ret;
}

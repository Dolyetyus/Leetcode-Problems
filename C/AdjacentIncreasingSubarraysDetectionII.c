int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }

int maxIncreasingSubarrays(int* nums, int numsSize) {
    int* sizes = (int*)malloc(numsSize * sizeof(int));
    int count = 0;
    int start = 0;
    int ret = 0;
    int maks = 0;

    for (int i = 1; i<=numsSize; i++) {
        if (i == numsSize || nums[i] <= nums[i-1]) {
            if (i-start>maks) maks = i-start;
            sizes[count] = i-start;
            count++;
            start = i;
        }
    }

    for (int i = 1; i<count; i++) {
        ret = max(ret, min(sizes[i], sizes[i-1]));
    }

    free(sizes);

    return max(ret, maks/2);
}

long long maximumTripletValue(int* nums, int numsSize) {
    long long maxEl = nums[0];
    long long maxDiff = 0;
    long long ret = 0;
    int updated_index = 0;

    for (int i = 0; i<numsSize; i++){
        int curr = nums[i];
        if (maxDiff * curr > ret) ret = maxDiff * curr;
        if (maxEl - curr > maxDiff) maxDiff = maxEl - curr;
        if (curr > maxEl) maxEl = curr;
    }

    return ret;
}

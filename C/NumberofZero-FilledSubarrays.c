long long zeroFilledSubarray(int* nums, int numsSize) {
    long long ret = 0;
    int right = 0;
    int left = 0;

    while (right<=numsSize) {
        while (right<numsSize && nums[right] != 0) right++;
        left = right;
        while (right<numsSize && nums[right] == 0) right++;

        long long size = right-left;
        ret += (size+1)*size/2;
        right++;
    }

    return ret;
}

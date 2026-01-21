int* minBitwiseArray(int* nums, int numsSize, int* returnSize) {
    int* ret = malloc(numsSize * sizeof(int));
    *returnSize = numsSize;

    for (int i = 0; i<numsSize; i++) {
        if (nums[i] == 2) {
            ret[i] = -1;
            continue;
        }

        int num = nums[i];
        int pos = 0;
        while (num != 0) {
            if (num%2 == 0) {
                ret[i] = nums[i] ^ (1 << pos-1);
                break;
            }
            num = num >> 1;
            pos++;
        }
        if (num == 0) ret[i] = nums[i] ^ (1 << pos-1);
    }

    return ret;
}

int* minBitwiseArray(int* nums, int numsSize, int* returnSize) {
    int* ret = calloc(numsSize, sizeof(int));
    *returnSize = numsSize;

    for (int i = 0; i<numsSize; i++) {
        if (nums[i] == 2) {
            ret[i] = -1;
            continue;
        }

        unsigned int can = 0;
        while (can < nums[i]) {
            if ((can | (can+1)) == nums[i]) {
                ret[i] = can;
                break;
            }
            can++;
        }
    }

    return ret;
}

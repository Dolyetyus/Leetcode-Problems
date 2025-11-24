bool* prefixesDivBy5(int* nums, int numsSize, int* returnSize) {
    bool* ret = malloc(numsSize*sizeof(bool));
    *returnSize = numsSize;
    int num = nums[0];
    ret[0] = !(nums[0] % 5);

    for (int i = 1; i<numsSize; i++) {
        num *= 2;
        if (nums[i] == 1) num++;

        if (num%5 == 0) ret[i] = true;
        else ret[i] = false;

        num %= 5;
    }

    return ret;
}

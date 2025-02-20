char* findDifferentBinaryString(char** nums, int numsSize) {
    int n = strlen(nums[0]);
    char *ret = malloc(n+1);
    ret[n] = '\0';

    for (int i = 0; i<numsSize; i++){
        ret[i] = nums[i][i] == '0' ? '1' : '0';
    }

    return ret;
}

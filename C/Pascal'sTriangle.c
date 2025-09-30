int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex+1;
    int* ret = calloc(rowIndex+1, sizeof(int));

    ret[0] = 1;
    if (rowIndex==0) return ret;
    ret[1] = 1;
    if (rowIndex==1) return ret;

    int level = 2;
    int prev = 1;
    while (ret[rowIndex] != 1) {
        for (int i = level; i > 0; i--) {
            ret[i] = ret[i] + ret[i-1];
        }
        ret[level] = 1;
        level++;
    }

    return ret;
}

int minDeletionSize(char** strs, int strsSize) {
    int ret = 0;
    for (int i = 0; strs[0][i]!='\0'; i++) {
        for (int ii = 1; ii<strsSize; ii++) {
            if (strs[ii][i] < strs[ii-1][i]) { 
                ret++;
                break;
            }
        }
    }

    return ret;
}

int minDeletionSize(char** strs, int strsSize) {
    if (strsSize<2) return 0;
    int len = strlen(strs[0]);
    bool sorted[strsSize-1];
    memset(sorted, false, sizeof(sorted));
    int ret = 0;

    for (int col = 0; col < len; col++) {
        bool bad = false;
        for (int i = 0; i < strsSize - 1; i++) {
            if (!sorted[i] && strs[i][col] > strs[i+1][col]) {
                bad = true;
                break;
            }
        }

        if (bad) {
            ret++;
            continue;
        }

        for (int i = 0; i<strsSize-1; i++) {
            if (!sorted[i] && strs[i][col] < strs[i+1][col]) sorted[i] = true;
        }
    }

    return ret;
}

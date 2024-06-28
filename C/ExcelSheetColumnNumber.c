int titleToNumber(char* columnTitle) {
    int ret = 0;

    for (int i = 0; i < strlen(columnTitle); i++){
        ret = ret * 26 + (columnTitle[i] - 'A' + 1);
    }

    return ret;
}

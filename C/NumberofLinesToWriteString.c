int* numberOfLines(int* widths, int widthsSize, char * s, int* returnSize){
    *returnSize = 2;
    int* ret = (int*)malloc(2 * sizeof(int));
    int lines = 1;
    int width = 0;

    for (int i = 0; i<strlen(s); i++) {
        if (width + widths[s[i]-'a'] > 100) {
            lines++;
            width = widths[s[i]-'a'];
        }
        else width += widths[s[i]-'a'];
    }

    ret[0] = lines;
    ret[1] = width;
    return ret;
}

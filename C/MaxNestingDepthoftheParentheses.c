int maxDepth(char* s) {
    int curr = 0;
    int ret = 0;
    for (int i = 0; s[i]!='\0'; i++) {
        if (s[i] == '(') {
            curr++;
            ret = fmax(curr, ret);
        }
        else if (s[i] == ')') curr--;
    }

    return ret;
}

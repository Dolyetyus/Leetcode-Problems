bool checkOnesSegment(char* s) {
    bool flag = false;

    for (int i = 0; s[i]!='\0'; i++) {
        if (!flag && s[i]=='0') flag = !flag;
        if (flag && s[i]=='1') return false;
    }

    return true;
}

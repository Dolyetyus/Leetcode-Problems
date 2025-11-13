int maxOperations(char* s) {
    int ret = 0;
    int ones = 0;

    if (s[0] == '1') ones++;

    for (int i = 1; s[i] != '\0'; i++) {
        if (s[i] == '1') ones++;
        if (s[i-1] == '1' && s[i] == '0') ret += ones;
    }

    return ret;
}

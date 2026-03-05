int minOperations(char* s) {
    int zero = 0;
    int one = 0;
    bool flag = true;

    for (int i = 0; s[i]!='\0'; i++) {
        if (flag) {
            if (s[i] == '0') one++;
            else zero++;
        }
        else {
            if (s[i] == '1') one++;
            else zero++;
        }

        flag = !flag;
    }

    return fmin(zero, one);
}

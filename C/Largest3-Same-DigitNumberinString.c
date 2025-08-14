char* largestGoodInteger(char* num) {
    char* ret = malloc(4);
    ret[3] = '\0';
    int max = -1;
    int n = strlen(num);

    for (int i = 0; i<n-2; i++){
        bool check = true;
        char digit = num[i];
        for (int ii = 0; ii<3; ii++){
            if (num[i+ii] != digit) {
                check = false;
                break;
            }
        }

        if (check && digit-'0' > max) {
            ret[0] = digit;
            ret[1] = digit;
            ret[2] = digit;
            max = digit-'0';
        }
    }

    if (max==-1) return "";

    return ret;
}

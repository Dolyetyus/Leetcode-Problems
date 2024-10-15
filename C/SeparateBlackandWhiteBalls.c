long long minimumSteps(char* s) {
    int n = strlen(s);
    long count = 0;
    long ret = 0;

    for (int i = n-1; i>=0; i--){
        if (s[i]=='0') count++;
        else ret += count;
    }

    return ret;
}

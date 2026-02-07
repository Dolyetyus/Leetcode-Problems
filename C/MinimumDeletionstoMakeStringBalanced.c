int minimumDeletions(char* s) {
    int bCount = 0;
    int ret = 0;

    for(int i = 0; s[i]!='\0'; i++) {
        if (s[i] == 'b') bCount++;
        else ret = fmin(ret+1, bCount);
    }

    return ret;
}

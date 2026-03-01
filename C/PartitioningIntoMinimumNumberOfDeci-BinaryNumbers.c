int minPartitions(char* n) {
    int ret = 0;
    for (int i = 0; n[i] != '\0'; i++) ret = fmax(ret, n[i]-'0');
    return ret;
}

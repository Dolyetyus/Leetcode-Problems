int minChanges(char* s) {
    int ret = 0;
    for (int i = 0; s[i]!='\0'; i+=2){
        if (s[i]!=s[i+1]) ret++;
    }
    return ret;
}

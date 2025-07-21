char* makeFancyString(char* s) {
    int len = strlen(s);
    char* ret = malloc((len+1) * sizeof(char));
    int write = 1; 
    int consecutive = 1;

    ret[0] = s[0];

    for (int i = 1; i<len; i++) {
        if (s[i] == s[i - 1]) consecutive++;
        else consecutive = 1;
        if (consecutive <= 2) ret[write++] = s[i];
    }

    ret[write] = '\0';
    return ret;
}

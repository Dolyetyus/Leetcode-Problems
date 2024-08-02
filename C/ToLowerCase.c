char* toLowerCase(char* s) {
    for (int i = 0; i<strlen(s); i++){
        if (isalpha(s[i]) && s[i]<91) s[i] += 32;
    }

    return s;
}

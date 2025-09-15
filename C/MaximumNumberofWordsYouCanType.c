int canBeTypedWords(char* text, char* brokenLetters) {
    int* hmap = calloc(26, sizeof(int));
    int ret = 0;
    bool valid = true;

    for (int i = 0; brokenLetters[i]!='\0'; i++){
        hmap[brokenLetters[i]-'a'] = 1;
    }

    for (int i = 0; text[i]!='\0'; i++){
        if (text[i] == ' ' && valid) ret++;
        else if (text[i] == ' ') valid = true;
        else if (hmap[text[i]-'a']==1) valid = false;
    }

    if (valid) ret++;

    return ret;
}

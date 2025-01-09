int prefixCount(char** words, int wordsSize, char* pref) {
    int n = strlen(pref);

    int ret = 0;
    for (int i = 0; i<wordsSize; i++){
        if (strncmp(pref, words[i], n) == 0) ret++;
    }

    return ret;
}

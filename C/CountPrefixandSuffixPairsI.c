int countPrefixSuffixPairs(char** words, int wordsSize) {
    int ret = 0;

    for (int i = 0; i<wordsSize; i++){
        for (int ii = i+1; ii<wordsSize; ii++){
            int n = strlen(words[i]);
            int m = strlen(words[ii]);
            if (n>m) continue;
            if (strncmp(words[i], words[ii], n) == 0 && strncmp(words[ii]+m-n, words[i], n) == 0) ret++;
        }
    }

    return ret;
}

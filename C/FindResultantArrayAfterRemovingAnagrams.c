char** removeAnagrams(char** words, int wordsSize, int* returnSize) {
    int* hmap1 = calloc(26, sizeof(int));
    int* hmap2 = calloc(26, sizeof(int));
    char** ret = malloc(sizeof(char*));
    int retIndex = 0;

    ret[retIndex++] = strdup(words[0]);

    for (int i = 1; i<wordsSize; i++) {
        // push to hmaps
        printf("%s ", words[i]);
        for (int x = 0; words[i][x]!='\0'; x++) hmap1[words[i][x]-'a']++;
        for (int y = 0; words[i-1][y]!='\0'; y++) hmap2[words[i-1][y]-'a']++;

        // compare hmaps
        bool isAnagram = true;
        for (int n = 0; n<26; n++) {
            if (hmap1[n] != hmap2[n]) {
                isAnagram = false;
                break;
            }
        }

        // clear hmaps
        memset(hmap1, 0, 26*sizeof(int));
        memset(hmap2, 0, 26*sizeof(int));

        // realloc and push if needed
        if (!isAnagram) {
            ret = realloc(ret, (retIndex+1) * sizeof(char*));
            ret[retIndex] = strdup(words[i]);
            retIndex++;
        }
    }

    *returnSize = retIndex;
    return ret;
}

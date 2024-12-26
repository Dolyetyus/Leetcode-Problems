void countingSortVowels(char* vowels, int size) {
    int count[128] = {0};

    for (int i = 0; i < size; ++i) {
        count[vowels[i]]++;
    }

    int index = 0;
    for (int i = 0; i < 128; ++i) {
        while (count[i]-- > 0) {
            vowels[index++] = (char)i;
        }
    }
}

char* sortVowels(char* s) {
    int size = 0;
    int n = strlen(s);

    bool isVowel[128] = {0};
    isVowel['a'] = isVowel['A'] = isVowel['e'] = isVowel['E'] = true;
    isVowel['i'] = isVowel['I'] = isVowel['o'] = isVowel['O'] = true;
    isVowel['u'] = isVowel['U'] = true;

    for (int i = 0; i < n; i++) {
        if (isVowel[(int)s[i]]) {
            size++;
        }
    }

    char* vowels = malloc(size);
    int idx = 0;

    for (int i = 0; i < n; i++) {
        if (isVowel[(int)s[i]]) {
            vowels[idx++] = s[i];
        }
    }

    countingSortVowels(vowels, size);

    idx = 0;
    for (int i = 0; i < n; i++) {
        if (isVowel[(int)s[i]]) {
            s[i] = vowels[idx++];
        }
    }

    free(vowels);
    return s;
}

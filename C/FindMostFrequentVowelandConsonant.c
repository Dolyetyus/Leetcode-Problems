int maxFreqSum(char* s) {
    int* hmap = calloc(26, sizeof(int));

    for (int i = 0; s[i]!='\0'; i++) {
        hmap[s[i]-'a']++;
    }

    int maxVowel = 0;
    int maxCons = 0;
    for (int i = 0; i<26; i++){
        if (i==0 || i==4 || i=='i'-'a' || i=='o'-'a' || i=='u'-'a') {
            if (hmap[i]>maxVowel) maxVowel = hmap[i];
        }
        else {
            if (hmap[i]>maxCons) maxCons = hmap[i];
        }
    }

    return maxVowel+maxCons;
}

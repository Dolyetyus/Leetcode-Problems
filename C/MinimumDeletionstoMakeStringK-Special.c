int comp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int minimumDeletions(char* word, int k) {
    int* map = calloc(26, 4);
    int n = strlen(word);

    for (int i = 0; i<n; i++) map[word[i]-'a']++;

    qsort(map, 26, sizeof(int), comp);

    int ret = n;
    for (int x = 0; x<=map[25]; x++) {
        int deletions = 0;
        for (int i = 0; i<26; i++) {
            if (map[i] == 0) continue;
            if (map[i] < x) deletions += map[i]; 
            else if (map[i] > x + k) deletions += map[i] - x - k;
        }
        if (deletions < ret)ret = deletions;
    }

    return ret;
}

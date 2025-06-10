int maxDifference(char* s) {
    int* hmap = calloc(26, sizeof(int));
    
    for (int i=0; s[i]!='\0'; i++){
        hmap[s[i]-'a']++;
    }

    int maxOdd = 0;
    int minEven = 999999;
    for (int i=0; i<26; i++){
        if (hmap[i]==0) continue;
        if (hmap[i]%2==1 && hmap[i]>maxOdd) maxOdd = hmap[i];
        else if (hmap[i]%2==0 && hmap[i]<minEven) minEven = hmap[i];
    } 

    free(hmap);
    return maxOdd-minEven;
}

char* firstPalindrome(char** words, int wordsSize) {
    for (int i = 0; i<wordsSize; i++){
        int n = strlen(words[i]);
        bool flag = true;
        for (int ii = 0; ii<n/2; ii++){
            if (words[i][ii]!=words[i][n-1-ii]) {
                flag = false;
                break;
            }
        }
        if (flag) return words[i];
    }
    return "";
}

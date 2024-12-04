bool canMakeSubsequence(char* str1, char* str2) {
    int n1 = strlen(str1);
    int n2 = strlen(str2);
    int first = 0;
    int second = 0;

    while (first<n1 && second<n2){
        if (str1[first]==str2[second] || (str1[first]+1-'a')%26 + 'a' == str2[second]) {
            second++;
        }
        first++;
    }

    return n2==second;
}

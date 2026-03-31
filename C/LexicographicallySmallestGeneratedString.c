char* generateString(const char* str1, const char* str2) {
    int n = strlen(str1), m = strlen(str2);
    int len = n+m-1;
    char* s = (char*)malloc((len+1)*sizeof(char));
    int* fixed = (int*)calloc(len, sizeof(int));

    for (int i = 0; i<len; i++) s[i] = 'a';
    s[len] = '\0';

    for (int i = 0; i < n; i++) {
        if (str1[i] == 'T') {
            for (int j = i; j < i + m; j++) {
                if (fixed[j] == 1 && s[j] != str2[j - i]) {
                    free(s);
                    free(fixed);
                    return "";
                } 
                else {
                    s[j] = str2[j-i];
                    fixed[j] = 1;
                }
            }
        }
    }

    for (int i = 0; i<n; i++) {
        if (str1[i] == 'F') {
            int flag = 0;
            int idx = -1;
            for (int j = i+m-1; j>=i; j--) {
                if (str2[j - i] != s[j]) flag = 1;
                if (idx == -1 && fixed[j] == 0) idx = j;
            }
            if (flag) continue;
            else if (idx != -1) s[idx] = 'b';
            else {
                free(s);
                free(fixed);
                return "";
            }
        }
    }

    free(fixed);
    return s;
}

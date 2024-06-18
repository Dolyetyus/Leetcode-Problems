int strStr(char* haystack, char* needle) {
    if (strlen(needle)>strlen(haystack)) return -1;

    for (int i = 0; i <= strlen(haystack) - strlen(needle); i++) {
        bool found = true;
        for (int ii = 0; ii < strlen(needle); ii++) {
            if (haystack[i+ii] != needle[ii]) {
                found = false;
                break;
            }
        }
        if (found) return i;
    }
    return -1;
}

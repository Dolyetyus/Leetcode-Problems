bool compare(char* s, char* part, int si, int size) {
    if (si + size > strlen(s)) return false;
    for (int i = 0; i < size; i++) {
        if (s[si + i] != part[i]) return false;
    }
    return true;
}

char* removeOccurrences(char* s, char* part) {
    int target_size = strlen(part);
    if (target_size == 0 || target_size > strlen(s)) {
        return s;
    }

    int n = strlen(s);
    int i = 0;

    while (i <= n - target_size) {
        if (s[i] == part[0] && compare(s, part, i, target_size)) {
            memmove(s+i, s+i+target_size, (n - (i + target_size) + 1));
            n -= target_size; 
            i = i - (target_size - 1);
            if (i < 0) i = 0;
        } 
        else i++;
    }

    return s;
}

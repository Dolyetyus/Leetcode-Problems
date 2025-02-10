char* clearDigits(char* s) {
    int n = strlen(s);
    int numDigits = 0;
    int erased = 0;

    for (int i = n-1; i>=0; i--){
        if (isdigit(s[i])) {
            numDigits++;
            erased++;
            s[i] = '-';
        }
        else if (numDigits>0) {
            erased++;
            s[i] = '-';
            numDigits--;
        }
    }

    if (erased==0) return s;

    char* ret = malloc((n-erased+1)*sizeof(char));
    ret[n-erased] = '\0';
    int id = 0;

    for (int i = 0; i<n-erased; i++){
        while (s[id]=='-') id++;
        ret[i] = s[id];
        id++;
    }

    return ret;
}

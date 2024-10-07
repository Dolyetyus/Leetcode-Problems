int minLength(char * s){
    int n = strlen(s);

    for (int i = 0; i<n-1; i++){
        if ((s[i] == 65 && s[i+1] == 66) || (s[i] == 67 && s[i+1] == 68)){
            memmove(&s[i], &s[i + 2], n - i - 1);
            s[n - 2] = '\0';
            return minLength(s);
        }
    }

    return n;
}

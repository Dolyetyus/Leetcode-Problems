char* truncateSentence(char* s, int k) {
    int counter = 0;
    int i = 0;
    while (counter<k){
        if (s[i]=='\0') return s;
        else if (s[i]==' ') counter++;
        i++;
    }
    s[i-1] = '\0';
    return s;
}

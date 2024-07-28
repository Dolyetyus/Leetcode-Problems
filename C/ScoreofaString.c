int scoreOfString(char* s) {
    int sum = 0;
    for (int i = 0; i<strlen(s)-1; i++){
        int diff = s[i]-s[i+1];
        if (diff<0) sum -= diff;
        else sum += diff;
    }
    return sum;
}

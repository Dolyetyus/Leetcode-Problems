bool hasSameDigits(char* s) {
    int n = strlen(s);
    char prev = '-';
    char wait = '-';

    while (s[2]!='\0') {
        for (int i = n-2; i>=0; i--) {
            wait = (s[i]-'0'+s[i+1]-'0')%10+'0';
            if (prev!='-') s[i+1] = prev;
            prev = wait;
        }

        s[n-1] = '\0';
        s[0] = prev;
        n--;
    }

    return s[0]==s[1];
}

/* Lol this works only with int
bool hasSameDigits(char* s) {
    int n = 0;
    int new = 0;
    int m = 0;
    for (int i = 0; s[i]!='\0'; i++){
        n*=10;
        n+=s[i]-'0';
    }

    while (n>99) {
        while (n>9) {
            new = n%10;
            n /= 10;
            new += n%10;
            new %= 10;
            m *= 10;
            m += new;
            printf("%d ", m);
        }
        n = m;
        m = 0;
        printf("%d - ", n);
    }

    int x = n/10%10;
    if (n%10 == x) return true;

    return false;
}
*/

bool doesAliceWin(char* s) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i]=='a' || s[i]=='e' || s[i]=='o' || s[i]=='u' || s[i]=='i') return true;
    }

    return false;
}

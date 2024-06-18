int lengthOfLastWord(char* s) {
    const char chr[2] = " ";
    char *token = strtok(s, chr);
    int len = 0;
   
    while(token != NULL) {     
        len = strlen(token); 
        token = strtok(NULL, chr);
    }

    return len;
}

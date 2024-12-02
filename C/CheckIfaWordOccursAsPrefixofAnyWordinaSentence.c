int isPrefixOfWord(char* sentence, char* searchWord) {
    int n = strlen(searchWord);
    int current = 1;

    for (int i = 0; sentence[i]!='\0'; i++){
        if(searchWord[0]==sentence[i]){
            if (i == 0 || sentence[i-1] == ' '){
                bool found = true;
                for (int ii = 0; ii<n; ii++){
                    if (searchWord[ii] != sentence[i+ii]){
                        found = false;
                        break;
                    }
                }
                if (found) return current;
            }
        }
        if (sentence[i]==' ') current++;
    }

    return -1;
}

bool isValid(char* word) {
    int i = 0;
    bool chars = true;
    bool vowel = false;
    bool consonant = false;

    for (i = 0; word[i] != '\0'; i++){
        if (!isalnum(word[i])) {
            chars = false;
            break;
        }
        if (isalpha(word[i])) {
            char chr = tolower(word[i]);
            if (chr=='a' || chr=='e' || chr=='i' || chr=='o' || chr=='u') vowel = true;
            else consonant = true;
        }
    }

    return (i>=3) && chars && vowel && consonant; 
}

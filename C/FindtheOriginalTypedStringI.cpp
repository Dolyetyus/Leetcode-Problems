int possibleStringCount(char* word) {
    int left = 0;
    int right = 0;
    int ret = 1;

    while (left<=right){
        while (word[left]==word[right]) right++;
        if (right-left>1) ret+=right-left-1;
        if (word[right]=='\0') break;
        left=right;
    }

    return ret;
}

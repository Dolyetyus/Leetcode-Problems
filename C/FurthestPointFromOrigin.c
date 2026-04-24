int furthestDistanceFromOrigin(char* moves) {
    int right = 0;
    int left = 0;
    int free = 0;

    for (int i = 0; moves[i]!='\0'; i++) {
        if (moves[i] == 'L') left++;
        else if (moves[i] == 'R') right++;
        else free++;
    }

    return abs(right-left)+free;
}

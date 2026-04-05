bool judgeCircle(char* moves) {
    int horizontal = 0;
    int vertical = 0;

    for (int i = 0; moves[i]!='\0'; i++) {
        if (moves[i]=='U') vertical++;
        if (moves[i]=='D') vertical--;
        if (moves[i]=='R') horizontal++;
        if (moves[i]=='L') horizontal--;
    }

    return !(horizontal | vertical);
}

int numberOfBeams(char** bank, int bankSize) {
    int ret = 0;
    int prev = 0;
    int lasers = 0;

    for (int i = 0; i<bankSize; i++) {
        lasers = 0;
        for (int ii = 0; bank[i][ii]!='\0'; ii++)
            if (bank[i][ii]=='1') lasers++;

        if (lasers == 0) continue;
        ret += (lasers*prev);
        prev = lasers;
    }

    return ret;
}

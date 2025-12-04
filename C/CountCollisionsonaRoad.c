int countCollisions(char* directions) {
    int left = 0;
    int stay = 0;
    int right = 0;
    int ret = 0;

    for (int i = 0; directions[i]!='\0'; i++) {
        if (directions[i] == 'R') {
            right++;
            if (stay) stay = 0;
        }
        else if (directions[i] == 'S') {
            stay++;
            ret += right;
            right = 0;
        }
        else if (directions[i] == 'L') {
            if (stay) ret++;
            if (right) {
                ret += 1 + right;
                right = 0;
                stay++;
            }
        }
    }

    return ret;
}

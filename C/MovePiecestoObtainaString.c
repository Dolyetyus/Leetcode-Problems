bool canChange(char* start, char* target) {
    int s = 0;
    int t = 0;
    int slen = strlen(start);
    int tlen = strlen(target);

    if (slen != tlen) return false;

    while (s < slen || t < tlen) {
        while (s < slen && start[s] == '_') s++;
        while (t < tlen && target[t] == '_') t++;

        if ((s < slen) != (t < tlen)) return false;

        if (s < slen && t < tlen) {
            if (start[s] != target[t]) return false;

            if (start[s] == 'L' && s < t) return false;
            if (start[s] == 'R' && s > t) return false;
        }

        s++;
        t++;
    }

    return true;
}

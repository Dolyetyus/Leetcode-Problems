char* pushDominoes(char* dominoes) {
    int n = strlen(dominoes);
    int* force = (int*)calloc(n, sizeof(int));
    int f = 0;

    for (int i = 0; i < n; i++) {
        if (dominoes[i] == 'R') f = n;
        else if (dominoes[i] == 'L') f = 0;
        else if (f > 0) f--;
        force[i] += f;
    }

    f = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (dominoes[i] == 'L') f = n;
        else if (dominoes[i] == 'R') f = 0;
        else if (f > 0) f--;
        force[i] -= f;
    }

    char* result = (char*)malloc((n + 1) * sizeof(char));
    for (int i = 0; i < n; i++) {
        if (force[i] > 0) result[i] = 'R';
        else if (force[i] < 0) result[i] = 'L';
        else result[i] = '.';
    }
    result[n] = '\0';

    free(force);
    return result;
}

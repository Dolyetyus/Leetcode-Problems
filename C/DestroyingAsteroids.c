int comp(const void *a, const void *b) {
    int val_a = *(const int *)a;
    int val_b = *(const int *)b;
    
    if (val_a < val_b) return -1;
    if (val_a > val_b) return 1;
    return 0;
}

bool asteroidsDestroyed(int mass, int* asteroids, int asteroidsSize) {
    qsort(asteroids, asteroidsSize, sizeof(int), comp);

    long long mss = mass;
    for (int i = 0; i<asteroidsSize; i++) {
        if (mss<asteroids[i]) return false;
        mss += asteroids[i];
    }

    return true;
}

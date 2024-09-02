int chalkReplacer(int* chalk, int chalkSize, int k) {
    long total_cost = 0;

    for (int i = 0; i<chalkSize; i++){
        total_cost += chalk[i];
    }

    k %= total_cost;

    for (int i = 0; i<chalkSize; i++){
        if (chalk[i]>k) return i;
        k -= chalk[i];
    }

    return 0;
}

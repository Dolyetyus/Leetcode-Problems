int sort(const void *a, const void *b) {
    int int_a = *((int*)a);
    int int_b = *((int*)b);
    if (int_a < int_b) return -1;
    if (int_a > int_b) return 1;
    return 0;
}

long long maximumHappinessSum(int* happiness, int happinessSize, int k) {
    long long ret = 0;
    qsort(happiness, happinessSize, sizeof(int), sort);

    for (int i = 0; i<k; i++) {
        int currentHappiness = happiness[happinessSize-i-1]-i;
        if (currentHappiness > 0) ret += currentHappiness;
        else break;
    }

    return ret;
}

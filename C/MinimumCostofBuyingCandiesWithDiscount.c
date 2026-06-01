int comp(const void *a, const void *b) {
    int val_a = *(const int *)a;
    int val_b = *(const int *)b;
    
    if (val_a > val_b) return -1;
    if (val_a < val_b) return 1;
    return 0;
}

int minimumCost(int* cost, int costSize) {
    qsort(cost, costSize, sizeof(int), comp);

    int ret = 0;
    for (int i = 0; i<costSize; i++) {
        ret += cost[i];
        i++;
        if (i>=costSize) break;
        ret += cost[i];
        i++;
    }

    return ret;
}

int comp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int maxCount(int* banned, int bannedSize, int n, int maxSum) {
    int sum = 0;
    int ret = 0;
    int i = 1;

    int current = 0;
    qsort(banned, bannedSize, sizeof(int), comp);

    while (sum+i <= maxSum && i<=n){
        while (current < bannedSize && banned[current] < i) current++;

        if (current < bannedSize && banned[current] == i) {
            i++;
            continue;
        }

        sum += i;
        ret++;
        i++;
    }

    return ret;
}

int* sumZero(int n, int* returnSize) {
    int* ret = malloc(n*sizeof(int));
    *returnSize = n;
    int i = 0;

    if (n%2==1) {
        ret[i] = 0;
        i++;
    }

    for (int x = 0-n/2; x <= n/2; x++) {
        if (x==0) continue;
        ret[i] = x;
        i++;
    }

    return ret;
}

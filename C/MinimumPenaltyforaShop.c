int bestClosingTime(char* customers) {
    int n = strlen(customers);
    int minPenalty = 999999;
    int ret = -1;
    int* prefix = malloc((n+1)*sizeof(int));
    int* suffix = malloc((n+1)*sizeof(int));

    prefix[0] = 0;
    for (int i = 1; i<=n; i++) {
        prefix[i] = (int)(customers[i-1] == 'N') + prefix[i-1];
    }

    suffix[n] = 0;
    for (int i = n-1; i>=0; i--) {
        suffix[i] = (customers[i] == 'Y') + suffix[i+1];
    }

    for (int i = 0; i<=n; i++) {
        if (prefix[i]+suffix[i] < minPenalty) {
            ret = i;
            minPenalty = prefix[i]+suffix[i];
        }
    }

    free(prefix);
    free(suffix);
    
    return ret;
}

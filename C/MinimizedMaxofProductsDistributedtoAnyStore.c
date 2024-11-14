int compare(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

bool canDistribute(int* quantities, int m, int n, int x) {
    int storesNeeded = 0;
    for (int i = 0; i < m; i++) {
        storesNeeded += (quantities[i] + x - 1) / x; 
        if (storesNeeded > n) return false;
    }
    return true;
}

int minimizedMaximum(int n, int* quantities, int m) {
    qsort(quantities, m, sizeof(int), compare);
    
    unsigned long long low = 1, high = 0;
    for (int i = 0; i < m; i++) {
        high += quantities[i];
    }
    
    while (low < high) {
        unsigned long long mid = low + (high - low) / 2;
        if (canDistribute(quantities, m, n, mid))
            high = mid;
        else
            low = mid + 1;
    }
    
    return low;
}

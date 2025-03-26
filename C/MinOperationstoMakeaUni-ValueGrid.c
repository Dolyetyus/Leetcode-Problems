int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int minOperations(int** grid, int gridSize, int* gridColSize, int x) {
    int m = gridSize, n = gridColSize[0];
    int size = m*n;
    int* arr = (int*)malloc(size*sizeof(int));
    
    int index = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            arr[index++] = grid[i][j];
        }
    }

    int remainder = arr[0] % x;
    for (int i = 1; i < size; i++) {
        if (arr[i] % x != remainder) {
            free(arr);
            return -1;
        }
    }

    qsort(arr, size, sizeof(int), cmp);
    int median = arr[size / 2];
    int operations = 0;

    for (int i = 0; i < size; i++) {
        operations += abs(arr[i]-median) / x;
    }

    free(arr);
    return operations;
}

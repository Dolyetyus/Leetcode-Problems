int** construct2DArray(int* original, int originalSize, int m, int n, int* returnSize, int** returnColumnSizes) {
    if (m*n != originalSize) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    int** result = (int**)malloc(m * sizeof(int*));
    *returnColumnSizes = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; ++i) {
        result[i] = original + i * n;
        (*returnColumnSizes)[i] = n;
    }

    *returnSize = m;
    return result;
}

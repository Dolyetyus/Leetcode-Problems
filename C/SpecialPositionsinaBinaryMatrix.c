int numSpecial(int** mat, int matSize, int* matColSize) {
    int m = matSize;
    int n = matColSize[0];
    int row_sum[100];
    int col_sum[100];
    
    for (int i = 0; i < m; i++) {
        row_sum[i] = 0;
        for (int j = 0; j < n; j++) {
            row_sum[i] += mat[i][j];
        }
    }
    
    for (int j = 0; j < n; j++) {
        col_sum[j] = 0;
        for (int i = 0; i < m; i++) {
            col_sum[j] += mat[i][j];
        }
    }
    
    int ret = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 1 && row_sum[i] == 1 && col_sum[j] == 1) {
                ret++;
            }
        }
    }
    
    return ret;
}

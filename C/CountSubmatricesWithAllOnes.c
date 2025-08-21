int numSubmat(int** matrix, int rows, int* colsizes) {
    int cols = colsizes[0];
    int** height = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) height[i] = (int*)calloc(cols, sizeof(int));

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (matrix[r][c] == 1) {
                if (r == 0) height[r][c] = 1;
                else height[r][c] = height[r - 1][c] + 1;
            } 
            else {
                height[r][c] = 0;
            }
        }
    }

    int ret = 0;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            int minHeight = height[r][c];
            for (int k = c; k >= 0 && minHeight > 0; k--) {
                if (height[r][k] == 0) break;
                if (height[r][k] < minHeight) minHeight = height[r][k];
                ret += minHeight;
            }
        }
    }

    return ret;
}

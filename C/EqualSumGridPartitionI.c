bool canPartitionGrid(int** grid, int gridSize, int* gridColSize) {
    int rows = gridSize;
    int cols = gridColSize[0];
    long long total = 0;

    for (int i = 0; i<rows; i++) {
        for (int j = 0; j< cols; j++) {
            total += grid[i][j];
        }
    }

    if (total%2 != 0) return false;

    long long target = total/2;
    long long colSum = 0;
    for (int c = 0; c<cols-1; c++) {
        for (int r = 0; r<rows; r++) {
            colSum += grid[r][c];
        }
        if (colSum == target) return true;
    }

    long long rowSum = 0;
    for (int r = 0; r < rows-1; r++) {
        for (int c = 0; c < cols; c++) {
            rowSum += grid[r][c];
        }
        if (rowSum == target) return true;
    }

    return false;
}

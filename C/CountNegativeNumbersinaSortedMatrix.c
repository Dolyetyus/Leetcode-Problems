int countNegatives(int** grid, int gridSize, int* gridColSize) {
    int ret = 0;
    for (int i = 0; i<gridSize; i++) {
        for (int ii = gridColSize[0]-1; ii>=0; ii--) {
            if (grid[i][ii] >= 0) break;
            ret++;
        }
    }

    return ret;
}

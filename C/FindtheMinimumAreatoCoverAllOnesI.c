int minimumArea(int** grid, int gridSize, int* gridColSize) {
    int minRow = 1000;
    int maxRow = 0;
    int minCol = 1000;
    int maxCol = 0;

    for (int i = 0; i<gridSize; i++){
        for (int ii = 0; ii<gridColSize[0]; ii++){
            if (grid[i][ii] == 1) {
                if (i<minRow) minRow = i;
                if (i>maxRow) maxRow = i;
                if (ii<minCol) minCol = ii;
                if (ii>maxCol) maxCol = ii;
            }
        }
    }

    return (maxRow+1-minRow)*(maxCol+1-minCol);
}

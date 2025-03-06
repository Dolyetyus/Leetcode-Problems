int* findMissingAndRepeatedValues(int** grid, int gridSize, int* gridColSize, int* returnSize) {
    int* checkList = calloc(gridSize*gridSize, sizeof(int));
    int* ret = malloc(2*sizeof(int));
    *returnSize = 2;

    for (int i = 0; i<gridSize; i++){
        for (int ii = 0; ii<gridSize; ii++) {
            checkList[grid[i][ii]-1]++;
            if (checkList[grid[i][ii]-1]==2) ret[0] = grid[i][ii];
        }
    }

    for (int i = 0; i<gridSize*gridSize; i++){
        if (checkList[i]==0) ret[1] = i+1;
    }

    return ret;
}

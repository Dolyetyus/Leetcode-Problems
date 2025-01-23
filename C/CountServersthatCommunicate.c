int countServers(int** grid, int gridSize, int* gridColSize) {
    int ret = 0;

    for (int i = 0; i<gridSize; i++){
        bool found = false;
        int count = 1;
        int firstX;
        int firstY;
        for (int ii = 0; ii<gridColSize[i]; ii++){
            if (grid[i][ii]==1 && !found){
                found = true;
                firstX = i;
                firstY = ii;
            }
            else if (grid[i][ii]==1){
                grid[i][ii] = 31;
                grid[firstX][firstY] = 31;
                count++;
            }
        }
        if (count>1) ret+=count;
    }

    for (int i = 0; i<gridColSize[0]; i++){
        bool found = false;
        bool valid = false;
        int count = 0;
        for (int ii = 0; ii<gridSize; ii++){
            if ((grid[ii][i]==1 || grid[ii][i]==31) && !found){
                found = true;
                if (grid[ii][i] == 1) count = 1;
            }
            else if ((grid[ii][i]==1 || grid[ii][i]==31)){
                if (grid[ii][i]==1) count++;
                valid = true;
            }
        }
        if (valid) ret+=count;
    }

    return ret;
}

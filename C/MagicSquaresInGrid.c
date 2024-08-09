int numMagicSquaresInside(int** grid, int gridSize, int* gridColSize) {
    int ret = 0;
    int idx = 0;
    int flattened[9];
    int possible_solutions[8][9] = {
        {8,3,4,1,5,9,6,7,2},
        {4,3,8,9,5,1,2,7,6},
        {8,1,6,3,5,7,4,9,2},
        {6,1,8,7,5,3,2,9,4},
        {2,9,4,7,5,3,6,1,8},
        {4,9,2,3,5,7,8,1,6},
        {2,7,6,9,5,1,4,3,8},
        {6,7,2,1,5,9,8,3,4}};

    for (int x = 0; x<gridSize-2; x++){
        for (int y = 0; y<gridColSize[x]-2; y++){
            for (int i = 0; i<3; i++){
                for (int ii = 0; ii<3; ii++){
                    flattened[idx] = grid[x+i][y+ii];
                    idx++;
                }
            }
            idx = 0;

            for (int i = 0; i<8; i++){
                if (memcmp(flattened, possible_solutions[i], sizeof(flattened))==0){
                    ret++;
                    break;
                }
            }
        }
    }

    return ret;
}

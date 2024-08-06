int maximumWealth(int** accounts, int accountsSize, int* accountsColSize) {
    int max = 0;
    
    for (int i = 0; i<accountsSize; i++){
        int total = 0;
        for (int ii = 0; ii<accountsColSize[i]; ii++){
            total += accounts[i][ii];
        }
        if (total>max) max=total;
    }

    return max;
}

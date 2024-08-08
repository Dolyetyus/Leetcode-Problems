void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    for (int i=0; i<matrixSize/2; i++){
        int* temp = matrix[i];
        matrix[i] = matrix[matrixSize-1-i];
        matrix[matrixSize-1-i] = temp;
    }

    for (int i=0; i<matrixSize; i++) {
        for (int j = i+1; j<matrixSize; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

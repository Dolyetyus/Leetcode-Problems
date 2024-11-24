long long maxMatrixSum(int** matrix, int matrixSize, int* matrixColSize) {
    int negatives = 0;
    int biggest = 99999999;
    long long sum = 0;
    for (int i = 0; i<matrixSize; i++){
        for (int ii = 0; ii<matrixSize; ii++){
            if (matrix[i][ii]<0) negatives++;
            sum+=abs(matrix[i][ii]);
            if (abs(matrix[i][ii])<biggest) biggest = abs(matrix[i][ii]);
        }
    }

    if (negatives%2==0) return sum;
    return sum-biggest-biggest;
}

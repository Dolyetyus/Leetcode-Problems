bool checkRotation(int** mat, int** target, int n) {
    for (int i = 0; i<n; i++) {
        for (int ii = 0; ii<n; ii++) {
            if (mat[i][ii] != target[i][ii]) return false;
        }
    }

    return true;
}

bool findRotation(int** mat, int matSize, int* matColSize, int** target, int targetSize, int* targetColSize) {
    if (checkRotation(mat, target, matSize)) return true;

    for (int it = 0; it<3; it++) {
        for (int i = 0; i<matSize; i++) {
            for (int j = i+1; j<matSize; j++) {
                int temp = mat[i][j];
                mat[i][j] = mat[j][i];
                mat[j][i] = temp;
            }
        }

        for (int i = 0; i<matSize; i++) {
            for (int j = 0; j<matSize/2; j++) {
                int temp = mat[i][j];
                mat[i][j] = mat[i][matSize-1-j];
                mat[i][matSize-1-j] = temp;
            }
        }

        if (checkRotation(mat, target, matSize)) return true;
    }

    return false;
}

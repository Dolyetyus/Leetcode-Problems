int count(int** matrix, int rows, int cols, int squareSize) {
    int ret = 0;

    for (int y = 0; y <= rows - squareSize; y++) {
        for (int x = 0; x <= cols - squareSize; x++) {
            int isValid = 1;
            for (int i = 0; i < squareSize; i++) {
                for (int j = 0; j < squareSize; j++) {
                    if (matrix[y + i][x + j] != 1) {
                        isValid = 0;
                        break;
                    }
                }
                if (!isValid) break;
            }
            if (isValid) ret++;
        }
    }

    return ret;
}

int countSquares(int** matrix, int rows, int* colsizes) {
    int ret = 0;
    int cols = colsizes[0];
    int maxSide = rows < cols ? rows : cols;

    for (int i = 1; i <= maxSide; i++) {
        ret += count(matrix, rows, cols, i);
    }

    return ret;
}

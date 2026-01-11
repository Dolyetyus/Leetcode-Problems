int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize) {
    if (matrixSize == 0) return 0;
    int cols = matrixColSize[0];
    int maxArea = 0;
    
    int widths[matrixSize][cols];

    for (int i = 0; i < matrixSize; i++) {
        for (int j = cols - 1; j >= 0; j--) {
            if (matrix[i][j] == '1') widths[i][j] = (j == cols - 1) ? 1 : 1 + widths[i][j+1];
            else widths[i][j] = 0;
        }
    }

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < cols; j++) {
            if (widths[i][j] == 0) continue;
            
            int min_w = widths[i][j];
            for (int k = i; k < matrixSize && widths[k][j] > 0; k++) {
                if (widths[k][j] < min_w) min_w = widths[k][j];
                int area = min_w * (k - i + 1);
                if (area > maxArea) maxArea = area;
            }
        }
    }
    return maxArea;
}

/* Testcases passed 74/75 because of fucking char overflow failing at 200*200
int maximalRectangle(char** horizontal, int matrixSize, int* matrixColSize) {
    for (int i = 0; i<matrixSize; i++) {
        for (int ii = 0; ii<matrixColSize[0]; ii++) {
            horizontal[i][ii] -= '0';
        }
    }

    int ret = 0;
    char vertical[matrixSize][matrixColSize[0]];
    for (int i = 0; i<matrixSize; i++) memcpy(vertical[i], horizontal[i], matrixColSize[0]*sizeof(char));

    for (int i = matrixSize-1; i>=0; i--) {
        for (int ii = matrixColSize[0]-1; ii>=0; ii--) {
            if (horizontal[i][ii] == 1) {
                if (ii+1 < matrixColSize[0] && horizontal[i][ii+1] != 0) horizontal[i][ii] += (horizontal[i][ii+1]-0);
                if (i+1 < matrixSize && vertical[i+1][ii] != 0) vertical[i][ii] += (vertical[i+1][ii]-0);
            } 
            else {
                horizontal[i][ii] = 0;
                vertical[i][ii] = 0;
            }
        }
    }

    for (int i = 0; i<matrixSize; i++) {
        for (int ii = 0; ii<matrixColSize[0]; ii++) {
            if (horizontal[i][ii] == 0) continue;

            int h = vertical[i][ii]-0;
            int min_w = horizontal[i][ii]-0;

            for (int k = 0; k<h; k++) {
                int current_row_w = horizontal[i+k][ii]-0;
                min_w = fmin(min_w, current_row_w);
                ret = fmax(ret, min_w*(k+1));
            }
        }
    }

    return ret;
}
*/

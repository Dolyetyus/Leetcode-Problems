int areaOfMaxDiagonal(int** dimensions, int dimensionsSize, int* dimensionsColSize) {
    int maxArea = 0;
    int maxDiag = 0;

    for (int i = 0; i<dimensionsSize; i++) {
        int diag = (dimensions[i][0]*dimensions[i][0])+(dimensions[i][1]*dimensions[i][1]);
        int area = dimensions[i][0]*dimensions[i][1];
        if (diag > maxDiag) {
            maxDiag = diag;
            maxArea = area;
        }
        else if (diag == maxDiag && area > maxArea)
            maxArea = area;
    }

    return maxArea;
}

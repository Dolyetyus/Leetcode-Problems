int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
    for (int i = triangleSize-2; i>=0; i--){
        for (int ii = 0; ii<=i; ii++){
            triangle[i][ii] += fmin(triangle[i+1][ii], triangle[i+1][ii+1]);
        }
    }

    return triangle[0][0];
}

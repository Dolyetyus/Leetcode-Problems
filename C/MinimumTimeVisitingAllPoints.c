int minTimeToVisitAllPoints(int** points, int pointsSize, int* pointsColSize) {
    int ret = 0;
    for (int i = 0; i<pointsSize-1; i++) {
        ret += fmax(abs(points[i][0]-points[i+1][0]), abs(points[i][1]-points[i+1][1]));
    }

    return ret;
}

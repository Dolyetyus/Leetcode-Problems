int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int findMinDifference(char** timePoints, int timePointsSize) {
    int min = 1441;
    int diff = 0;
    qsort(timePoints, timePointsSize, sizeof(const char *), compare);

    for (int i = 0; i<timePointsSize-1; i++){
        diff = abs((((timePoints[i][0]-'0') * 10 + (timePoints[i][1]-'0'))*60 + (timePoints[i][3]-'0') * 10 + (timePoints[i][4]-'0')) - (((timePoints[i+1][0]-'0') * 10 + (timePoints[i+1][1]-'0'))*60 + (timePoints[i+1][3]-'0') * 10 + (timePoints[i+1][4]-'0')));
        if (diff<min) min = diff;
    }

    diff = abs((((timePoints[0][0]-'0') * 10 + (timePoints[0][1]-'0'))*60 + (timePoints[0][3]-'0') * 10 + (timePoints[0][4]-'0') + 1440) - (((timePoints[timePointsSize-1][0]-'0') * 10 + (timePoints[timePointsSize-1][1]-'0'))*60 + (timePoints[timePointsSize-1][3]-'0') * 10 + (timePoints[timePointsSize-1][4]-'0')));
    if (diff<min) min = diff;

    return min;
}

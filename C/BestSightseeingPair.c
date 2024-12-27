int maxScoreSightseeingPair(int* values, int valuesSize) {
    int ret = 0;
    int max = 0;

    for (int i = 0; i<valuesSize; i++){
        ret = values[i] - i + max > ret? values[i] - i + max : ret;
        
        int score = values[i] + i;
        if (score > max) max = score;
    }

    return ret;
}

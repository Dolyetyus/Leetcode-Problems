int minCost(char* colors, int* neededTime, int neededTimeSize) {
    int total = 0;
    int maxTime = neededTime[0];

    for (int i = 1; i < neededTimeSize; i++) {
        if (colors[i] == colors[i-1]) {
            total += fmin(maxTime, neededTime[i]);
            maxTime = fmax(maxTime, neededTime[i]);
        } 
        else maxTime = neededTime[i];
    }

    return total;
}

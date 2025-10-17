int minCostClimbingStairs(int* cost, int costSize) {
    cost = realloc(cost, (costSize+1)*sizeof(int));
    cost[costSize] = 0;
    int i = costSize-2;

    while (i>=0){
        if (cost[i+1]<cost[i+2]) cost[i] += cost[i+1];
        else cost[i] += cost[i+2];
        i--;
    }

    if (cost[0]<cost[1]) return cost[0];
    return cost[1];
}

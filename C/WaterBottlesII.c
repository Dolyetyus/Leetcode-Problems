int maxBottlesDrunk(int numBottles, int numExchange) {
    if (numBottles < numExchange) return numBottles;
    int drank = numBottles;
    int empty = numBottles;

    while (empty >= numExchange) {
        empty -= numExchange++;
        drank++;
        empty++;
    }

    return drank;
}

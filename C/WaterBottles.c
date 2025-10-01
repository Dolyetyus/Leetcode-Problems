int numWaterBottles(int numBottles, int numExchange) {
    if (numBottles < numExchange) return numBottles;
    int drank = numBottles;
    int empty = 0;

    while (numBottles >= numExchange) {
        empty = numBottles%numExchange;
        numBottles = (numBottles/numExchange) + empty;
        drank += numBottles - empty;
    }

    return drank;
}

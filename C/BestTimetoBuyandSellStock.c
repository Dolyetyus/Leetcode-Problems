int maxProfit(int* prices, int pricesSize) {
    int ret = 0;
    int current = 9999999;

    for (int i = 0; i<pricesSize; i++){
        if (prices[i]<current) current = prices[i];

        if (prices[i]-current > ret) ret=prices[i]-current;
    }

    return ret;
}

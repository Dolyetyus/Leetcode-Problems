long long getDescentPeriods(int* prices, int pricesSize) {
    long long ret = 0;
    long long streak = 1;

    for (int i = 1; i<pricesSize; i++) {
        if (prices[i-1]-prices[i] != 1) {
            ret += (streak*(streak+1))/2;
            streak = 1;
        }
        else streak++;

        if (i == pricesSize-1) ret += (streak*(streak+1))/2;
    }
    
    if (!ret) return 1;
    return ret;
}

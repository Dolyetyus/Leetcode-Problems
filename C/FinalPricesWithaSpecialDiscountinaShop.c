int* finalPrices(int* prices, int pricesSize, int* returnSize) {
    *returnSize = pricesSize;

    for (int i = 0; i<pricesSize; i++){
        for (int ii = i+1; ii<pricesSize; ii++){
            if (prices[ii]<=prices[i]){
                prices[i]-=prices[ii];
                break;
            }
        }
    }

    return prices;
}

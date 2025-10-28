int coinChange(int* coins, int coinsSize, int amount) {
    int* dp = calloc(amount+1, sizeof(int));

    for (int i = 0; i<=amount; i++) dp[i] = amount+1;
    dp[0] = 0;

    for (int i = 0; i<=amount; i++) {
        for (int n = 0; n < coinsSize; n++) {
            if (coins[n] <= i) dp[i] = fmin(dp[i], 1 + dp[i-coins[n]]);
        }
    }

    return dp[amount]>amount ? -1 : dp[amount];
}

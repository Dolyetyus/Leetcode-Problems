int numOfSubarrays(int* arr, int arrSize) {
    const long long MOD = 1000000007;
    long long evenCount = 1;
    long long oddCount = 0;
    long long ret = 0;
    int prefixParity = 0;

    for (int i = 0; i < arrSize; i++) {
        prefixParity = (prefixParity + (arr[i] % 2)) % 2;

        if (prefixParity == 0) {
            ret = (ret + oddCount) % MOD;
            evenCount++;
        } 
        else {
            ret = (ret + evenCount) % MOD;
            oddCount++;
        }
    }

    return (int)ret;
}

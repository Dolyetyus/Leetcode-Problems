int countPermutations(int* complexity, int complexitySize) {
    int smallest = complexity[0];
    int bigger = 0;
    int ret = 1;

    for (int i = 1; i<complexitySize; i++) {
        if (complexity[i]>smallest) bigger++;
        else if (complexity[i]<=smallest) return 0;
    }

    for (int i = 1; i<=bigger; i++) {
        __int128 temp = ( __int128 )ret*i;
        ret = (long long)(temp % 1000000007);
    }

    return ret;
}

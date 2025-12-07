int countOdds(int low, int high){
    int ret = (high-low)/2;

    if (low%2 || high%2) ret++;

    return ret;
}

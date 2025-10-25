int totalMoney(int n) {
    int ret = 0;
    int start = 1;
    int curr = start;
    
    for (int i = 1; i<=n; i++){
        ret += curr;
        curr++;
        if (i%7==0) {
            start++;
            curr = start;
        }
    }

    return ret;
}

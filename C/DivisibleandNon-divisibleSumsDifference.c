int differenceOfSums(int n, int m) {
    int sum = (n+1)*n/2;
    int minus = 0;
    for (int i = m; i<=n; i+=m){
        minus += i; 
    }

    return sum-minus-minus;
}

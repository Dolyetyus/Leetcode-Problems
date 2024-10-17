int pivotInteger(int n) {
    int sum = (n+1)*n/2;

    for (int i = 1; i<n+1; i++){
        int tempSum = sum + i;
        int nSum = (i+1)*i/2;
        if (tempSum - nSum == nSum) return i;
    }

    return -1;
}

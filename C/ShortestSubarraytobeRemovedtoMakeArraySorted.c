int findLengthOfShortestSubarray(int* arr, int n) {
    int i = 0;
    while (i < n-1 && arr[i] <= arr[i+1]) {
        i++;
    }
    
    if (i == n-1) return 0;
    
    int j = n-1;
    while (j > 0 && arr[j-1] <= arr[j]) {
        j--;
    }
    
    int ret = j;
    ret = (n - i - 1 < ret) ? (n - i - 1) : ret;

    int k = 0;
    while (k <= i && j < n) {
        if (arr[k] <= arr[j]) {
            ret = (j - k - 1 < ret) ? (j - k - 1) : ret;
            k++;
        } 
        else {
            j++;
        }
    }
    
    return ret;
}

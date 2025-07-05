int findLucky(int* arr, int arrSize) {
    int* freq = calloc(500, sizeof(int));

    for (int i = 0; i<arrSize; i++) freq[arr[i]-1]++;

    for (int i = 499; i>=0; i--){
        if (i+1==freq[i]) return i+1;
    }
    
    return -1;
}

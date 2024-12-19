int maxChunksToSorted(int* arr, int arrSize) {
    int ret = 0;
    int max = arr[0];
    for (int i = 0; i < arrSize; i++) {
        max = arr[i] > max ? arr[i] : max;
        if (max == i) ret++;
    }
    return ret;
}

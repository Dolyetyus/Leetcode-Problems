int compare(const void* a, const void* b){
    int int_a = *(const int*)a;
    int int_b = *(const int*)b;

    int bits_a = __builtin_popcount(int_a);
    int bits_b = __builtin_popcount(int_b);

    if (bits_a != bits_b) return bits_a-bits_b;

    return int_a-int_b;
}

int* sortByBits(int* arr, int arrSize, int* returnSize) {
    *returnSize = arrSize;
    qsort(arr, arrSize, sizeof(int), compare);

    return arr;
}

bool isZeroArray(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize) {
    int *check = calloc(sizeof(int), numsSize+1);
    for (int i = 0; i<queriesSize; i++) {
        check[queries[i][0]]++;
        check[queries[i][1]+1]--;
    }
    
    int sub = 0;
    for (int i = 0; i<numsSize; i++){
        sub+=check[i];
        if (nums[i]-sub>0) return false;
    }

    return true;
}

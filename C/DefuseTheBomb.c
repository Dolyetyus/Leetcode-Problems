int* decrypt(int* code, int codeSize, int k, int* returnSize) {
    *returnSize = codeSize;
    if (k==0) {
        memset(code, 0, codeSize*sizeof(int));
        return code;
    }

    int* or_arr = malloc(sizeof(int)*codeSize);
    memcpy(or_arr, code, codeSize*sizeof(int));

    for (int i = 0; i<codeSize; i++){
        int sum = 0;
        if (k > 0) {
            for (int ii = 1; ii<=k; ii++) {
                int index = (i+ii) % codeSize;
                sum += code[index];
            }
        } 
        else if (k < 0) {
            for (int ii = -1; ii>=k; ii--) {
                int index = (i+ii+codeSize) % codeSize;
                sum += code[index];
            }
        }
        or_arr[i] = sum;
    }

    return or_arr;    
}

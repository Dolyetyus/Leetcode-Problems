int* findFactors(int n, int *size){
    int i = 1;
    *size = 0;
    int *ret_arr = malloc(0);

    while (i<=n/2){
        if (n % i == 0){
            (*size)++;
            ret_arr = realloc(ret_arr, sizeof(int)*(*size));
            ret_arr[(*size)-1] = i;
        }
        i++;
    }

    (*size)++;
    ret_arr = realloc(ret_arr, sizeof(int)*(*size));
    ret_arr[(*size)-1] = n;

    return ret_arr;
}

int kthFactor(int n, int k) {
    int size = 0;
    int* factor_arr = findFactors(n, &size);
    return (k>size) ? -1 : factor_arr[k-1];
}

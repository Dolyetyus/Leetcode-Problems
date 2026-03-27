void reverse(int* arr, int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void rotateRight(int* arr, int size, int n) {
    reverse(arr, 0, size-n-1);
    reverse(arr, size-n, size-1);
    reverse(arr, 0, size-1);
}

void rotateLeft(int* arr, int size, int n) {
    reverse(arr, 0, n-1);
    reverse(arr, n, size-1);
    reverse(arr, 0, size-1);
}

bool areSimilar(int** mat, int matSize, int* matColSize, int k) {
    k %= matColSize[0];
    int dup[matSize][matColSize[0]];
    for (int i = 0; i<matSize; i++) {
        memcpy(dup[i], mat[i], matColSize[0]*sizeof(int));
    }
    
    for (int i = 0; i<matSize; i++) {
        if (i%2 == 1) rotateRight(mat[i], matColSize[0], k);
        else rotateLeft(mat[i], matColSize[0], k);
    }

    for (int i = 0; i<matSize; i++) {
        for (int ii = 0; ii<matColSize[0]; ii++) {
            if (dup[i][ii] != mat[i][ii]) return false;
        }
    }

    return true;
}

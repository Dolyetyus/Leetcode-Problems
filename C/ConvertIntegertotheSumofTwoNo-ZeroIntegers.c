bool isNonZero(int n) {
    while (n>0){
        if (n%10==0) return false;
        n/=10;
    }

    return true;
}

int* getNoZeroIntegers(int n, int* returnSize) {
    int x = n-1;
    int y = 1;

    *returnSize = 2;
    int* ret = malloc(2*sizeof(int));

    while (!isNonZero(x) || !isNonZero(y)){
        x--;
        y++;
    }

    ret[0] = x;
    ret[1] = y;

    return ret;
}

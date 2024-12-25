int* stableMountains(int* height, int heightSize, int threshold, int* returnSize) {
    int arrSize = 0;
    int *ret = malloc(arrSize);

    for (int i = 1; i<heightSize; i++){
        if (height[i-1]>threshold){
            arrSize++;
            ret = realloc(ret, arrSize*sizeof(int));
            ret[arrSize-1] = i;
        }
    }

    *returnSize = arrSize;
    return ret;
}

typedef struct {
    int value;
    int index;
} Pair;

int compare(const void *a, const void *b) {
    return ((Pair *)a)->value - ((Pair *)b)->value;
}

int maxWidthRamp(int* nums, int numsSize) {
    int max = 0;
    int min = 99999999;
    Pair pairs[numsSize];

    for (int i = 0; i < numsSize; i++) {
        pairs[i].value = nums[i];
        pairs[i].index = i;
    }

    qsort(pairs, numsSize, sizeof(Pair), compare);

    for (int i = 0; i<numsSize; i++){
        if (pairs[i].index < min) {
            min = pairs[i].index;
        } 
        else {
            int width = pairs[i].index - min;
            if (width > max) {
                max = width;
            }
        }
    }

    return max;
}

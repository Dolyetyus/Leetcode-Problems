int maxFrequencyElements(int* nums, int numsSize) {
    int* hmap = calloc(100, sizeof(int));
    int maxFreq = 0;
    int ret = 0;

    for (int i = 0; i<numsSize; i++) {
        hmap[nums[i]-1]++;
    }

    for (int i = 0; i<100; i++) {
        if (hmap[i]>maxFreq) {
            maxFreq = hmap[i];
            ret = hmap[i];
        }
        else if (hmap[i]==maxFreq) {
            ret+=hmap[i];
        }
    }

    return ret;
}

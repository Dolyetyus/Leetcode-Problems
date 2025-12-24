int minimumBoxes(int* apple, int appleSize, int* capacity, int capacitySize) {
    int *hmap = calloc(51, sizeof(int));
    int ret = 0;
    int total = 0;

    for (int i = 0; i<capacitySize; i++) hmap[capacity[i]]++;
    for (int i = 0; i<appleSize; i++) total += apple[i];

    int i = 50;
    while (total>0) {
        if (hmap[i]==0) i--;
        else {
            total -= i;
            hmap[i]--;
            ret++;
        }
    }
    
    free(hmap);
    return ret;
}

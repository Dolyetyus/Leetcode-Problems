int minNumberOperations(int* target, int targetSize) {
    if (targetSize<3) return fmax(target[0], target[1]);

    int ret = 0;
    for (int i = 1; i<targetSize; i++) {
        if (target[i] < target[i-1]) ret += target[i-1] - target[i];
    }

    return ret+target[targetSize-1];
}

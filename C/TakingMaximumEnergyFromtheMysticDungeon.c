int maximumEnergy(int* energy, int energySize, int k) {
    for (int i = energySize-k-1; i>=0; i--) {
        energy[i] += energy[i+k];
    }

    int ret = -2147483648;
    for (int i = 0; i<energySize; i++) {
        if (energy[i]>ret) ret = energy[i];
    }

    return ret;
}

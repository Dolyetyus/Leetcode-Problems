bool doesValidArrayExist(int* derived, int derivedSize) {
    int sum = derived[0];

    for (int i = 1; i<derivedSize; i++){
        sum = (sum && !derived[i]) || (!sum && derived[i]);
    }

    return !sum;
}
